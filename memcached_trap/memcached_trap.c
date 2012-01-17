/*
 * DISCLAIMER: I have never used memcached till now. So this is specific to a twitter request
 *
 * Just trap the memcached_mget routine to force NOTFOUND errors as requested by 
 * Gopal.V a.k.a @t3rmin4t0r the great!
 * The trap below should work as seen with a quick test run with test_memcached but the disclaimer above holds :)
 */
#include <stdio.h>
#include <dlfcn.h>
#include <libmemcached-1.0/memcached.h>

typedef memcached_return_t (memcached_mget_fun_t) (memcached_st *p, const char *const *keys,
                                                   const size_t *key_length, size_t number_of_keys); 

#define MGET_TRAP_ALIAS(sym)                                            \
    memcached_return_t sym(memcached_st *p, const char *const *keys,    \
                           const size_t *key_length, size_t number_of_keys) \
         __attribute__((weak, alias("__trap_"#sym)))

#define MGET_TRAP_DEFINE(sym)                                           \
memcached_return_t __trap_##sym(memcached_st *p, const char *const *keys, \
                                const size_t *key_length, size_t number_of_keys) \
{                                                                       \
    memcached_mget_fun_t *orig_##sym = dlsym(RTLD_NEXT, #sym);          \
    if(!orig_##sym)                                                     \
    {                                                                   \
        fprintf(stderr, "Unable to resolve symbol [%s]. Error [%s]\n", #sym, dlerror()); \
        exit(EXIT_FAILURE);                                             \
    }                                                                   \
    return __do_trap_##sym(orig_memcached_mget, p, keys, key_length, number_of_keys); \
}                                                                       \
MGET_TRAP_ALIAS(sym);

static memcached_return_t __do_trap_memcached_mget(memcached_mget_fun_t *orig_fun,
                                                   memcached_st *p,
                                                   const char *const *keys,
                                                   const size_t *key_length, size_t number_of_keys)
{
    printf("Inside memcached mget. Orig mget at [%p]\n", orig_fun);
    //return orig_fun(p, keys, key_length, number_of_keys);
    printf("Forcing not found error\n");
    return MEMCACHED_NOTFOUND;
}                                                   

MGET_TRAP_DEFINE(memcached_mget)                                                   
                                                                                                     
                                                  
