/**
 * SO, 2014 - Lab #07, Profiling
 * Task #2, Linux
 *
 * Column major
 */
#include <stdio.h>

#define SIZE	8192

static unsigned char x[SIZE][SIZE];

int main(void)
{
	size_t i, j;

	for (i = 0; i < SIZE; ++i) {
		for (j = 0; j < SIZE; ++j) {
			x[j][i] = x[j][i] ^ 100;
		}
	}

	return 0;
}
