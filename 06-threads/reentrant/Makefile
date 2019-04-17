CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: reentrant reentrant-ok

reentrant: reentrant.o

reentrant.o: reentrant.c ../../util/util.h

reentrant-ok: reentrant-ok.o

reentrant-ok.o: reentrant.c ../../util/util.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -DUSE_REENTRANT -c -o $@ $<

clean:
	-rm -f *~
	-rm -f reentrant.o reentrant
	-rm -f reentrant-ok.o reentrant-ok
