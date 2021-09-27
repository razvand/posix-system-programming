CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused-parameter -g

.PHONY: all clean

all: ansi-to-posix

ansi-to-posix: ansi-to-posix.o

ansi-to-posix.o: ansi-to-posix.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f out
	-rm -f ansi-to-posix.o ansi-to-posix

