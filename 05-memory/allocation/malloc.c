/*
 * View virtual memory allocation
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"

#define NUM_ROUNDS	10

int main(void)
{
	char *p;
	size_t cnt, i;

	puts("Initializing.");
	sleep(5);

	for (cnt = 0; cnt < NUM_ROUNDS; cnt++) {
		puts("Using malloc to allocate 1024 sets of 1024 bytes.");
		for (i = 0; i < 1024; i++) {
			p = malloc(1024);
			DIE(p == NULL, "malloc");
		}
		sleep(2);
	}

	return 0;
}
