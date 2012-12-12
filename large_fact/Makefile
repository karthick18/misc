CC = gcc
CFLAGS = -Wall -O2
SRCS := large_fact.c
OBJS := $(SRCS:%.c=%.o)
TARGETS := large_fact

all: $(TARGETS)

large_fact: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *~ $(OBJS) $(TARGETS)