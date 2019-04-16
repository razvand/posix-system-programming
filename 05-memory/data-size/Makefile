CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: data-size

data-size: data-size.o

data-size.o: data-size.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f data-size.o data-size
