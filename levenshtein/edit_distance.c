/*
 * Compute the min. edit distance between 2 strings:
 * s = source string: len = n
 * t = target string: len = m
 * if s = 0 return m
 * if t = 0 return n 
 * distance matrix[n+1,m+1]
 * initialize d[[0...n],0] = [0...n]
 * initialize d[0,[0...n]] = [0...n]
 * for i in 1 <= n
 * for j in  1 <= m
 *
 * if s[i] == t[j] cost = 0
 * else cost = 1
 * d[i,j]  = min(1+ cell_above:d[i-1,j], 1+cell_to_the_left:d[i,j-1], cost+cell_diagonal_to_the_left:d[i-1,j-1])
 * 
 * end iterations
 * d[n,m]  is the edit distance
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#undef MIN
#define __MIN(x,y) ( (x) < (y) ? (x) : (y) )
#define MIN(a,b,c) __MIN(a, __MIN(b, c))

#ifdef TWO_D
static int compute_levenshtein(const char *s, const char *d)
{
    int **distance_matrix = NULL;
    int min_distance = 0;
    register int i, j;
    int n = strlen(s);
    int m = strlen(d);
    if(!n) return m;
    if(!m) return n;
    distance_matrix = calloc(n+1, sizeof(*distance_matrix));
    assert(distance_matrix);
    for(i = 0; i <= n; ++i)
    {
        distance_matrix[i] = calloc(m+1, sizeof(**distance_matrix));
        assert(distance_matrix[i]);
    }
    for(i = 0; i <= n; ++i)
        distance_matrix[i][0] = i;
    for(j = 0; j <= m; ++j)
        distance_matrix[0][j] = j;
    for(i = 1; i <= n; ++i)
    {
        char s1 = s[i-1];
        for(j = 1; j <= m ; ++j)
        {
            char d1 = d[j-1];
            int cost = 0;
            if(s1 != d1) cost = 1;
            distance_matrix[i][j] = 
                MIN(1 + distance_matrix[i-1][j],
                    1 + distance_matrix[i][j-1],
                    cost + distance_matrix[i-1][j-1]);
        }
    }
    min_distance = distance_matrix[n][m];
    for(i = 0; i <= n; ++i)
        free(distance_matrix[i]);
    free(distance_matrix);
    return min_distance;
}
#else
static int compute_levenshtein(const char *s, const char *d)
{
    int *distance_matrix = NULL;
    int min_distance = 0;
    register int i, j;
    int n = strlen(s);
    int m = strlen(d);
    if(!n) return m;
    if(!m) return n;

    distance_matrix = calloc((n+1) * (m+1), sizeof(*distance_matrix));
    assert(distance_matrix);
    for(i = 0; i <= n; ++i)
        distance_matrix[i*(m+1)] = i;

    for(j = 0; j <= m; ++j)
        distance_matrix[j] = j;

    for(i = 1; i <= n; ++i)
    {
        char s1 = s[i-1];
        for(j = 1; j <= m ; ++j)
        {
            char d1 = d[j-1];
            int cost = 0;
            if(s1 != d1) cost = 1;
            distance_matrix[i*(m+1) + j] = 
                MIN(1 + distance_matrix[(i-1)*(m+1) + j],
                    1 + distance_matrix[i*(m+1) + (j-1)],
                    cost + distance_matrix[(i-1)*(m+1) + (j-1)]);
        }
    }
    min_distance = distance_matrix[n*(m+1) + m];
    free(distance_matrix);
    return min_distance;
}
#endif

int main(int argc, char **argv)
{
    char *s = strdup("test");
    char *d = strdup("text");
    assert(s && d);
    if(argc > 1)
    {
        free(s);
        s = strdup(argv[1]);
    }
    if(argc > 2)
    {
        free(d);
        d = strdup(argv[2]);
    }
    fprintf(stdout, "Computing edit distance between strings [%s - %s]\n",
            s, d);
    fprintf(stdout, "Levenshtein distance : [%d]\n", compute_levenshtein(s, d));
    free(s), free(d);
    return 0;
}

