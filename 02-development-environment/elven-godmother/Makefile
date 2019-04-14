CFLAGS = -no-pie -m32 -O0 -Wall -fno-stack-protector -Wno-unused-function -mpreferred-stack-boundary=2
LDFLAGS = -no-pie -m32 -mpreferred-stack-boundary=2

.PHONY: all clean public

all: elven_godmother

elven_godmother: elven_godmother.o

elven_godmother.o: elven_godmother.c

clean:
	-rm -f *~ *.o
	-rm -f elven_godmother

public: elven_godmother
	cp elven_godmother ../public/
