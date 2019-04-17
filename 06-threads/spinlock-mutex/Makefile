CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: all clean

all: spinlock mutex

spinlock: spinlock.o

spinlock.o: spinlock.c ../../util/util.h

mutex: mutex.o

mutex.o: mutex.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f spinlock.o spinlock
	-rm -f mutex.o mutex
