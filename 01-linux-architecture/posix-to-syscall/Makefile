CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: posix-to-syscall

posix-to-syscall: posix-to-syscall.o

posix-to-syscall.o: posix-to-syscall.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f out
	-rm -f posix-to-syscall.o posix-to-syscall

