CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: dynamic-memory-size

dynamic-memory-size: dynamic-memory-size.o

dynamic-memory-size.o: dynamic-memory-size.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f dynamic-memory-size.o dynamic-memory-size
