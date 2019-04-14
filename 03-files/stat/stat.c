#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "util.h"

int main(void)
{
	int fd;
	struct stat sbuf;
	int ret;

	ret = stat("Makefile", &sbuf);
	DIE(ret < 0, "stat");

	printf("Makefile: inode: %lu, size: %ld, uid: %d\n", sbuf.st_ino, sbuf.st_size, sbuf.st_uid);

	fd = open("Makefile", O_RDONLY);
	DIE(fd < 0, "open");

	ret = fstat(fd, &sbuf);
	DIE(ret < 0, "stat");

	printf("Makefile: inode: %lu, size: %ld, uid: %d\n", sbuf.st_ino, sbuf.st_size, sbuf.st_uid);

	close(fd);

	return 0;
}
