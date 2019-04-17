CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: clean

all: thread-list-app thread-list-app-mutex

thread-list-app-mutex: thread-list-app-mutex.o list.o

thread-list-app-mutex.o: thread-list-app.c list.h ../../util/util.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $< -D USE_MUTEX

thread-list-app: thread-list-app.o list.o

thread-list-app.o: thread-list-app.c list.h ../../util/util.h

list.o: list.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f thread-list-app.o thread-list-app
	-rm -f thread-list-app-mutex.o thread-list-app-mutex
