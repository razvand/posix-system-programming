#include <stdio.h>
#include <stdlib.h>

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#include "util.h"

int main(void)
{
	puts("POSIX");
	write(STDOUT_FILENO, "POSIX\n", 6);
	syscall(SYS_write, STDOUT_FILENO, "POSIX\n", 6);
	return 0;
}
