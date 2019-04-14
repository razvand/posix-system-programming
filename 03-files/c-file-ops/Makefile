CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: c-file-ops

c-file-ops: c-file-ops.o

c-file-ops.o: c-file-ops.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f f.txt
	-rm -f c-file-ops.o c-file-ops
