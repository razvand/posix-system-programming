CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: fdtsize

fdtsize: fdtsize.o

fdtsize.o: fdtsize.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f aaa
	-rm -f fdtsize.o fdtsize

