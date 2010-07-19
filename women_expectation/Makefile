CC = gcc
DEBUG = -g
CFLAGS = -O2 -fomit-frame-pointer -I. $(DEBUG)
TARGET = womens_expectation
SRCS := expectation.c config.c 
OBJS := $(SRCS:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.i: %.c
	$(CC) $(CFLAGS) -E $< >$@

%.s: %.c
	$(CC) $(CFLAGS) -S $< >$@

clean:
	rm -f *.o *~ $(TARGET)
