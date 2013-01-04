CC = gcc
CFLAGS = -g -Wall -O2 -std=c99 -D_GNU_SOURCE
SRCS := safplus_hash.c md5.c
OBJS := $(SRCS:%.c=%.o)
TARGETS := safplus_consistent_hash

all: $(TARGETS)

safplus_consistent_hash:$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) $(OBJS) *~