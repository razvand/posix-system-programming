#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <pthread.h>

#include "util.h"

/* Do nothing, successfully. */
static void *empty_func(void *arg)
{
	return NULL;
}

int main(void)
{
	int fd;
	char buffer[128];
	pid_t pid;
	int ret;
	pthread_t tid;

	fd = open("aaa", O_RDWR | O_CREAT, 0644);
	DIE(fd < 0, "open");

	write(fd, "POSIX", 5);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 128);
	close(fd);

	pid = fork();
	if (pid <= 0)	/* in case of error or child process */
		exit(EXIT_SUCCESS);
	wait(NULL);

	ret = pthread_create(&tid, NULL, empty_func, NULL);
	DIE(ret < 0, "pthread_create");
	pthread_join(tid, NULL);

	return 0;
}
