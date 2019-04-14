CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: page-size

page-size: page-size.o

page-size.o: page-size.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f page-size.o page-size

