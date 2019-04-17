CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: malloc mmap

malloc: malloc.o

malloc.o: malloc.c ../../util/util.h

mmap: mmap.o

mmap.o: mmap.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f malloc.o malloc
	-rm -f mmap.o mmap
