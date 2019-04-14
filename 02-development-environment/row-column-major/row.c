/**
 * SO, 2014 - Lab #07, Profiling
 * Task #2, Linux
 *
 * Row major
 */
#include <stdio.h>

#define SIZE	8192

static unsigned char x[SIZE][SIZE];

int main(void)
{
	size_t i, j;

	for (i = 0; i < SIZE; ++i) {
		for (j = 0; j < SIZE; ++j) {
			x[i][j] = x[i][j] ^ 100;
		}
	}

	return 0;
}
