CC = gcc
CPPFLAGS = -I../../util/
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: cpu

cpu: cpu.o

cpu.o: cpu.c ../../util/util.h

clean:
	-rm -f *.o *~ cpu *.txt
