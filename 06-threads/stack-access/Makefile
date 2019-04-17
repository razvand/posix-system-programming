CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: stack-access

stack-access: stack-access.o

stack-access.o: stack-access.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f stack-access.o stack-access
