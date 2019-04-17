CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unsed -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: process thread

process: process.o

process.o: process.c ../../util/util.h

thread: thread.o

thread.o: thread.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f process.o process
	-rm -f thread.o thread
