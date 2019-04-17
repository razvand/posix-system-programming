#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "util.h"

#define SRC_FILENAME	"/var/cache/apt/pkgcache.bin"
#define DST_FILENAME	"local.bin"

int main(void)
{
	int src_fd, dst_fd;
	void *src_p, *dst_p;
	struct stat statbuf;
	int rc;

	src_fd = open(SRC_FILENAME, O_RDONLY);
	DIE(src_fd < 0, "open");

	dst_fd = open(DST_FILENAME, O_RDWR | O_CREAT | O_TRUNC, 0644);
	DIE(dst_fd < 0, "open");

	rc = fstat(src_fd, &statbuf);
	DIE(rc < 0, "fstat");

	/* Truncate destination file. */
	rc = ftruncate(dst_fd, statbuf.st_size);
	DIE(rc < 0, "fstat");

	/* Map files. */
	src_p = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, src_fd, 0);
	DIE(src_p == MAP_FAILED, "mmap");
	dst_p = mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, dst_fd, 0);
	DIE(dst_p == MAP_FAILED, "mmap");

	/* Do the copying. */
	memcpy(dst_p, src_p, statbuf.st_size);

	munmap(src_p, statbuf.st_size);
	munmap(dst_p, statbuf.st_size);

	/* Map files. */
	close(src_fd);
	close(dst_fd);

	return 0;
}
