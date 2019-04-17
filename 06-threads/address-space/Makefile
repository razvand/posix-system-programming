CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: address-space

address-space: address-space.o

address-space.o: address-space.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f address-space. address-space
