#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void wait_for_input(const char *msg)
{
	char buf[32];

	printf(" * %s\n", msg);
	printf(" -- Press ENTER to continue ...\n"); fflush(stdout);
	fgets(buf, 32, stdin);
}

int main(void)
{
	int fd1, fd2;

	wait_for_input("before everything");

	fd1 = open("a.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd1 < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	wait_for_input("after open(a.txt)");
	fd2 = open("a.txt", O_WRONLY);
	if (fd2 < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	wait_for_input("after open(a.txt)");

	write(fd1, "aaa", 3);
	write(fd2, "bbb", 3);
	write(fd1, "aaa", 3);
	write(fd2, "bb", 2);
	wait_for_input("after writes");

	return 0;
}
