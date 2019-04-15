CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: orphan

orphan: orphan.o

orphan.o: orphan.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f orphan.o orphan
