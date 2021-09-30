CC = gcc
CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: executor executor_ansi printer

executor: executor.o

executor.o: executor.c ../../util/util.h

executor_ansi: executor_ansi.o

executor_ansi.o: executor_ansi.c ../../util/util.h

printer: printer.o

printer.o: printer.c

clean:
	-rm -f executor executor.o
	-rm -f executor_ansi executor_ansi.o
	-rm -f printer printer.o
	-rm -f *~
