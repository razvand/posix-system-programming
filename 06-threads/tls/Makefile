CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: tls

tls: tls.o

tls.o: tls.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f tls.o tls
