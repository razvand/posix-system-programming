CC = gcc
CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: yield

yield: yield.o

yield.o: yield.c ../../util/util.h

clean:
	-rm -f *.o *~ yield
