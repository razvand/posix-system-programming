CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: stat

stat: stat.o

stat.o: stat.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f stat.o stat
