#include <stdio.h>
#include <stdlib.h>

#include "util.h"

int main(void)
{
	FILE *f;
	size_t i;

	for (i = 0; i < 1030; i++) {
		printf("i = %zu, open file\n", i);
		f = fopen("aaa", "w");
		DIE(f == NULL, "fopen");
	}

	printf("Opened %zu file descriptors.\n", i);

	return 0;
}
