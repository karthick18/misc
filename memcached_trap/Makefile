CC := gcc
LIB_SRCS := memcached_trap.c
LIB_OBJS := $(LIB_SRCS:%.c=%.o)
CFLAGS := -Wall -g -shared -fPIC -D_GNU_SOURCE
LIB_TRAP := libmemcached_trap.so
TARGETS := $(LIB_TRAP) test_memcached
LD_PRELOAD_FILE := /etc/ld.so.preload

all: $(TARGETS)

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<

test_memcached.o: test_memcached.c
	$(CC) -g -c -Wall -o $@ $<

test_memcached: test_memcached.o
	$(CC) -g -o $@ $^ -lmemcached

libmemcached_trap.so: $(LIB_OBJS)
	$(CC) -g -shared -o $@ $^ -ldl -lmemcached

clean:
	rm -f $(TARGETS) $(LIB_OBJS) test_memcached.o *~ 

install:
	echo "`pwd`/$(LIB_TRAP)" >> $(LD_PRELOAD_FILE)