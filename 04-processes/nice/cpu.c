#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"

int main(void)
{
	size_t i, j;
	size_t val = 0x12345678;

	for (i = 0; i < 10000000; i++) {
		val = val ^ i;
		for (j = 0; j < 300; j++)
			val = val ^ j;
	}

	return 0;
}
