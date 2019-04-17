CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: wild-run

wild-run: wild-run.o

wild-run.o: wild-run.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f wild-run.o wild-run
