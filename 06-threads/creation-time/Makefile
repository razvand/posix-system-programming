CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: process-overhead thread-overhead

process-overhead: process-overhead.o

process-overhead.o: process-overhead.c ../../util/util.h

thread-overhead: thread-overhead.o

thread-overhead.o: thread-overhead.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f process-overhead.o process-overhead
	-rm -f thread-overhead.o thread-overhead
