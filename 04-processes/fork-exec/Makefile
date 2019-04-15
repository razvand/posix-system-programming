CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: fork-exec

fork-exec: fork-exec.o

fork-exec.o: fork-exec.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f fork-exec.o fork-exec
