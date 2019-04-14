CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: fopen-perm

fopen-perm: fopen-perm.o

fopen-perm.o: fopen-perm.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f aaa
	-rm -f fopen-perm.o fopen-perm

