CC = gcc
CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: executor executor_ansi reader writer

executor: executor.o

executor.o: executor.c ../../util/util.h

executor_ansi: executor_ansi.o

executor_ansi.o: executor_ansi.c ../../util/util.h

reader: reader.o

reader.o: reader.c

writer: writer.o

writer.o: writer.c

clean:
	-rm -f executor executor.o
	-rm -f executor_ansi executor_ansi.o
	-rm -f reader reader.o
	-rm -f writer writer.o
	-rm -f *~
