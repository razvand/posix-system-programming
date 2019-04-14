CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: syscall-trace

syscall-trace: syscall-trace.o

syscall-trace.o: syscall-trace.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f syscall-trace.o syscall-trace

