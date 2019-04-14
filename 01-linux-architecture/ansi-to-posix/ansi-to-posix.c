#include <stdio.h>
#include <stdlib.h>

#include "util.h"

int main(void)
{
	FILE *src, *dst;
	unsigned char buffer[1024];

	src = fopen("/dev/urandom", "r");
	DIE(src == NULL, "fopen");

	dst = fopen("out", "w");
	DIE(dst == NULL, "fopen");

	fread(buffer, 1, 1024, src);
	fputs("POSIXPOSIXPOSIXPOSIX", dst);
	fwrite(buffer, 1, 1024, dst);

	fclose(src);
	fclose(dst);

	return 0;
}
