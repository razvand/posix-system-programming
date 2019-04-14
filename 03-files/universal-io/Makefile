CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: universal-io

universal-io: universal-io.o

universal-io.o: universal-io.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f universal-io.o universal-io
