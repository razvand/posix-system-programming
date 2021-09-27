#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#include "util.h"

int main(void)
{
	int fd;

	puts("POSIX");
	write(STDOUT_FILENO, "POSIX\n", 6);
	syscall(SYS_write, STDOUT_FILENO, "POSIX\n", 6);


	fd = open("a.txt", O_CREAT | O_WRONLY, 0644);
	write(fd, "hello\n", 6);
	close(fd);

	return 0;
}
