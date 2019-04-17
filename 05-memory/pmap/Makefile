CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: pmap

pmap: pmap.o

pmap.o: pmap.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f pmap.o pmap
