#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/timerfd.h>

#include "util.h"

int main(void)
{
	int fd;
	int dirfd;
	int sockfd;
	int sockfd_unix;
	int pipefd[2];
	int timerfd;
	int ret;

	fd = open("Makefile", O_RDONLY);
	DIE(fd < 0, "open");

	dirfd = open("/etc", O_DIRECTORY | O_RDONLY);
	DIE(dirfd < 0, "open");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	DIE(sockfd < 0, "socket");

	sockfd_unix = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	DIE(sockfd_unix < 0, "socket");

	ret = pipe(pipefd);
	DIE(ret < 0, "pipe");

	timerfd = timerfd_create(CLOCK_REALTIME, 0);
	DIE(timerfd < 0, "timerfd_create");

	sleep(100);

	close(fd);
	close(dirfd);
	close(sockfd);
	close(sockfd_unix);
	close(pipefd[0]);
	close(pipefd[1]);
	close(timerfd);

	return 0;
}
