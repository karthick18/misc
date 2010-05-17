CC := gcc
CFLAGS := -g -Wall
SRCS := love.c
OBJS := $(SRCS:%.c=%.o)
TARGET = love

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $<

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f *~ $(OBJS) $(TARGET)