CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: pipe

pipe: pipe.o

pipe.o: pipe.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f pipe.o pipe
