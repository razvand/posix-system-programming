#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"

int main(void)
{
	FILE *f;
	size_t i;

	for (i = 0; i < 10; i++) {
		printf("a");
		sleep(1);
	}
	printf("\n");
	printf("stdout bufsize: %d\n", __fbufsize(stdout));

	f = fopen("aaa", "w");
	DIE(f == NULL, "fopen");

	for (i = 0; i < 10; i++) {
		fprintf(f, "a");
		fprintf(f, "\n");
		sleep(1);
	}
	printf("file bufsize: %d\n", __fbufsize(f));
	fflush(f);

	fclose(f);

	return 0;
}
