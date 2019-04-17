CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g -m32
LDFLAGS = -m32

.PHONY: all clean

all: mprotect

mprotect: mprotect.o

mprotect.o: mprotect.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f mprotect.o mprotect
