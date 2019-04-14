CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: posix-vs-syscall

posix-vs-syscall: posix-vs-syscall.o

posix-vs-syscall.o: posix-vs-syscall.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f aaa
	-rm -f posix-vs-syscall.o posix-vs-syscall

