CFLAGS = -Wall -Wextra -Wno-unused-variable -g

.PHONY: all clean

all: exec-vars

exec-vars: exec-vars.o

exec-vars.o: exec-vars.c

clean:
	-rm -f *~
	-rm -f exec-vars.o exec-vars
