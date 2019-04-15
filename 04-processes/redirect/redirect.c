#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include "util.h"

int main(void)
{
	int fd;

	/* redirection: first implementation */
#if 1
	close(1);
	fd = open("out", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	DIE(fd < 0, "open");
#endif

	/* redirection: second implementation */
#if 0
	fd = open("out", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	DIE(fd < 0, "open");
	close(1);
	dup(fd);
	close(fd);
#endif

	/* redirection: third implementation */
#if 0
	fd = open("out", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	DIE(fd < 0, "open");
	dup2(fd, 1);
	close(fd);
#endif

	puts("POSIXPOSIXPOSIXPOSIX");

	return 0;
}
