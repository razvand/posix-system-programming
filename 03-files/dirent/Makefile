CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: dirent

dirent: dirent.o

dirent.o: dirent.c ../../util/util.h

clean:
	-rm -f *~
	-rm -f dirent.o dirent
