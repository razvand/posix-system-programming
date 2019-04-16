CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: environ-with-fork environ-simple

environ-with-fork: environ-with-fork.o

environ-with-fork.o: environ-with-fork.c ../../util/util.h

environ-simple: environ-simple.o

environ-simple.o: environ-simple.c

clean:
	-rm -f *~
	-rm -f environ-with-fork.o environ-with-fork
	-rm -f environ-simple.o environ-simple
