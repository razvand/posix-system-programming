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
	FILE *f;
	int fd;

	wait_for_input("before everything");

	f = fopen("a.txt", "wt");
	if (f == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	printf("f->_fileno: %d\n", fileno(f));
	wait_for_input("after fopen(a.txt)");

	/*
	 * O_RDONLY: 3r
	 * O_WRONLY: 3w
	 * O_RDWR:   3u
	 */
	fd = open("b.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("fd: %d\n", fd);
	wait_for_input("after open(b.txt)");

	return 0;
}
