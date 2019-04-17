/*
 * View virtual memory allocation
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#include "util.h"

#define NUM_ROUNDS	10

int main(void)
{
	char *p;
	size_t cnt;

	puts("Initializing.");
	sleep(5);

	for (cnt = 0; cnt < NUM_ROUNDS; cnt++) {
		puts("Using mmap to allocate 1MB.");
		p = mmap(NULL, 1024*1024, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		DIE(p == MAP_FAILED, "mmap");
		sleep(2);
	}

	return 0;
}
