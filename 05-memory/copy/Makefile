CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: copy

copy: copy.o

copy.o: copy.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f local.bin
	-rm -f copy.o copy
