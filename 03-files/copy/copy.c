#include <stdio.h>
#include <stdlib.h>

#include "util.h"

#define SRC_FILENAME	"/var/cache/apt/pkgcache.bin"
#define DST_FILENAME	"local.bin"

static unsigned char buffer[8192];

int main(void)
{
	FILE *src, *dst;
	size_t nread, nwritten;

	src = fopen(SRC_FILENAME, "r");
	DIE(src == NULL, "open");

	dst = fopen(DST_FILENAME, "w");
	DIE(dst == NULL, "open");

	while (1) {
		nread = fread(buffer, 1, 8192, src);
		if (nread == 0)
			break;
		nwritten = 0;
		while (1) {
			size_t now_written;
			now_written = fwrite(buffer, 1, nread - nwritten, dst);
			if (now_written == 0)
				exit(EXIT_FAILURE);
			nwritten += now_written;
			if (nwritten == nread)
				break;
		}
	}

	fclose(src);
	fclose(dst);

	return 0;
}
