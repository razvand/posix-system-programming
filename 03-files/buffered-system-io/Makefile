CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: buffered system

buffered: buffered.o

buffered.o: buffered.c ../../util/util.h

system: system.o

system.o: system.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f aaa
	-rm -f buffered.o buffered
	-rm -f system.o system

