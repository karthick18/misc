#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define likely(expr) __builtin_expect(!!(expr), 1)
#define unlikely(expr) __builtin_expect(!!(expr), 0)

#define __EXTEND_MEM (256<<10)

static const size_t g_extend_mem = __EXTEND_MEM; /*extend result mem*/
static u_int8_t *g_buddies_mem[2];
static size_t g_buddies_res_mem[2];
static int g_buddy_index = 1;

static u_int8_t *__slow_multiply(u_int8_t *op1, u_int8_t *op2,
                                 int len_op2, int *p_len_res, size_t *p_offset_res)
{
    u_int8_t *res, *res_base, *iter_op2;
    int len_op1, len_res = 0, res_mem;
    int level = 0, i;
    int buddy_index = 0;
    if(likely(p_len_res && *p_len_res))
    {
        len_op1 = *p_len_res;
    }
    else len_op1 = strlen((const char*)op1);

    if(unlikely(!len_op2))
        len_op2 = strlen((const char *)op2);

    res_mem = len_op1 + len_op2 + 1;
    /*
     * Since op1 and op2 could be on the same mem., we alternate with our buddy 
     * since we would be accumulating results on every pass and don't wanna 
     * overwrite the result space while walking through operand op1
     */
    buddy_index = g_buddy_index ^ 1;
    g_buddy_index = buddy_index; /*next index*/

    res = res_base = g_buddies_mem[buddy_index];
    memset(res, 0, res_mem);

    iter_op2 = op2 + len_op2 - 1;
    /*
     * copy backwards
     */
    res = res_base + res_mem-1;
    *res-- = 0;
    while(iter_op2 >= op2)
    {
        int carry = 0, acc = 0;
        u_int8_t p = *iter_op2 - '0';
        u_int8_t *iter_op1 = op1 + len_op1 - 1;
        u_int8_t res_sum = 0;
        int res_curlen = 0;
        res = res_base + res_mem - 2;
        for(i = 0; i < level; ++i) 
        {
            --res; 
            ++res_curlen;
        }
        while(iter_op1 >= op1)
        {
            u_int8_t d = *iter_op1 - '0';
            u_int8_t sum = d * p;
            res_sum = *res ? *res - '0' : 0;
            sum += carry;
            carry = sum/10;
            res_sum += (sum%10) + acc;
            *res-- = (res_sum % 10) + '0';
            acc = res_sum/10;
            --iter_op1;
            ++res_curlen;
        }
        if(likely(acc || carry))
        {
            res_sum = *res ? *res - '0' : 0;
            res_sum += acc + carry;
            *res-- = (res_sum % 10) + '0';
            ++res_curlen;
            acc = res_sum/10;
            if(likely(acc))
            {
                *res-- = (acc <= 9) ? acc + '0' : acc;
                ++res_curlen;
            }
        }
        if(unlikely(res_curlen > len_res))
            len_res = res_curlen;
        --iter_op2;
        ++level;
    }

    ++res;
    if(likely(res > res_base))
    {
        if(likely(p_offset_res))
            *p_offset_res = res - res_base;
        else
            memmove(res_base, res, len_res+1);
    }
    else if(likely(p_offset_res)) *p_offset_res = 0;

    if(p_len_res) *p_len_res = len_res;

    buddy_index ^= 1;
    if(unlikely(len_res + 100 >= g_buddies_res_mem[buddy_index]))
    {
        g_buddies_res_mem[buddy_index] += g_extend_mem;
        g_buddies_mem[buddy_index] = realloc(g_buddies_mem[buddy_index], 
                                             g_buddies_res_mem[buddy_index]);
    }

#if 0
    printf("\n slow multiply result \n");
    while(*res)
    {
        if(*res <= '9')
            printf("%c", *res);
        else printf("%d", *res); 
        ++res;
    }
    printf("\nslow multiply result2 :%s\n", res_base + (p_offset_res ? *p_offset_res : 0));
#endif

    return res_base;
}

static unsigned long long __multiply(unsigned long long a, unsigned long long b, 
                                     u_int8_t **res_str, int *p_len_res,
                                     size_t *p_offset_res)
{
    char *s1 = NULL;
    char *s2 = NULL;
    char *b1, *b2;
    unsigned long long multiplier = 1;
    unsigned long long res = 0;
    if(a >= (1LL << 32)
       ||
       b >= (1LL << 32)) 
    {
        u_int8_t *cache_res = NULL;
        asprintf(&s1, "%llu", a);
        asprintf(&s2, "%llu", b);
        if(!res_str) res_str = &cache_res;
        *res_str = __slow_multiply((u_int8_t*)s1, (u_int8_t*)s2, 0, p_len_res, p_offset_res);
        free(s1); free(s2);
        if(cache_res) free(cache_res);
        return 0;
    }
    asprintf(&s1, "%llu", a);
    asprintf(&s2, "%llu", b);
    b1 = s1 + strlen(s1)-1;
    while(b1 >= s1)
    {
        unsigned long long product = 0;
        unsigned long long units = 1L;
        int p = *b1 - '0';
        b2 = s2 + strlen(s2) -1 ;
        while(b2 >= s2)
        {
            unsigned long long n = *b2 - '0';
            n *= units;
            n *= p;
            product += n;
            --b2;
            units *= 10L;
        }
        product *= multiplier;
        res += product;
        multiplier *= 10L;
        --b1;
    }
    free(s1), free(s2);
    return res;
}

static void do_fact(int n)
{
    unsigned long long res = 1;
    u_int8_t *res_str = NULL;
    u_int8_t *i_str = NULL;
    int i, len_res = 0, i_str_len = 1, last_str_len = 0, cur_radix = 10;
    size_t offset_res = 0;
    for(i = 2; i <= n; ++i)
    {
        if(!(i % cur_radix))
        {
            cur_radix *= 10;
            last_str_len = i_str_len;
            ++i_str_len;
        }
        if(!res_str)
        {
            res = __multiply(res, i, &res_str, &len_res, &offset_res);
        }
        else
        {
            if(last_str_len != i_str_len)
            {
                last_str_len = i_str_len;
                i_str = realloc(i_str, i_str_len + 1);
            }
            snprintf((char*)i_str, i_str_len+1, "%d", i);
            /*printf("Computing fact [%d] * [%d] -- [%s * %s]\n", i-1, i, 
              res_str + offset_res, i_str);*/
            res_str = __slow_multiply(res_str + offset_res, i_str, i_str_len,
                                      &len_res, &offset_res);
        }
    }
    if(res_str) 
    {
        printf("%s\n", 
               *(res_str + offset_res) == '0' ? res_str+offset_res+1 : res_str+offset_res);
    }
    else printf("%llu\n", res);
    if(i_str) free(i_str);
}

int main(int argc, char **argv)
{
    int i;
    int n = 0;
    int *loops;
    g_buddies_res_mem[0] = g_buddies_res_mem[1] = g_extend_mem;
    g_buddies_mem[0] = malloc(g_buddies_res_mem[0]);
    g_buddies_mem[1] = malloc(g_buddies_res_mem[1]);
    if(argc > 1)
    {
        do_fact(atoi(argv[1]) );
        goto out_free;
    }
    scanf("%d", &n);
    loops = calloc(n, sizeof(*loops));
    for(i = 0; i < n; ++i)
        scanf("%d", loops+i);

    for(i = 0; i < n; ++i)
        do_fact(loops[i]);

    free(loops);

    out_free:
    free(g_buddies_mem[0]);
    free(g_buddies_mem[1]);
    return 0;
}


/*
 * Local variables:
 * c-file-style: "linux"
 * compile-command: "gcc -O2 -o large_fact large_fact.c"
 * tab-width: 4
 * c-basic-offset: 4
 * End:
*/
