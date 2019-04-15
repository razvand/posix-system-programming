CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: redirect

redirect: redirect.o

redirect.o: redirect.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f out
	-rm -f redirect.o redirect
