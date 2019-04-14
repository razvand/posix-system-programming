CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: hello

hello: hello.o

hello.o: hello.s
	$(AS) -o $@ $<

hello.s: hello.c
	$(CC) -S -o $@ $<

clean:
	-rm -f *~
	-rm -f hello.s hello.o hello

