#include <stdio.h>
#include <assert.h>
#include <libmemcached-1.0/memcached.h>

int main()
{
    memcached_return_t r = memcached_mget(NULL, NULL, NULL, 0);
    printf("memcached mget returned with [%d]\n", r);
    assert(r == MEMCACHED_NOTFOUND);
    return 0;
}
