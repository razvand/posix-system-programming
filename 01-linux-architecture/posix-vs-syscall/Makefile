CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: posix-vs-syscall

posix-vs-syscall: posix-vs-syscall.o

posix-vs-syscall.o: posix-vs-syscall.c

clean:
	-rm -f *~
	-rm -f posix-vs-syscall.o posix-vs-syscall

