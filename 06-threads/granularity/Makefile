CPPFLAGS = -I../../util
CFLAGS = -Wall -Wextra -Wno-unused -Wno-unused-parameter -g
LDLIBS = -lpthread

.PHONY: clean

all: granularity-fine granularity-coarse

granularity-fine: granularity-fine.o

granularity-fine.o: granularity.c ../../util/util.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -DGRANULARITY_TYPE=2 -c -o $@ $<

granularity-coarse: granularity-coarse.o

granularity-coarse.o: granularity.c ../../util/util.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -DGRANULARITY_TYPE=1 -c -o $@ $<

clean:
	-rm -f *~
	-rm -f granularity-fine.o granularity-fine
	-rm -f granularity-coarse.o granularity-coarse
