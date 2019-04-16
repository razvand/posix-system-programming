#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include "util.h"

int main(void)
{
	pid_t pid;
	char *e;
	int rc;

	e = getenv("AUTHOR");
	if (e == NULL)
		printf("PID: %d (parent PID: %d): No environment variable named AUTHOR.\n", getpid(), getppid());
	else
		printf("PID: %d (parent PID: %d): AUTHOR=%s\n", getpid(), getppid(), e);

	pid = fork();
	switch (pid) {
	case -1:	/* error */
		DIE(pid < 0, "fork");
		break;

	case 0:		/* child process */
		/* Execute with no environment. */
		rc = execle("./environ-simple", "./environ-simple", NULL, NULL);
		DIE(rc < 0, "execle");

		return 0;

	default:	/* parent process: fall through */
		wait(NULL);
	}

	pid = fork();
	switch (pid) {
	case -1:	/* error */
		DIE(pid < 0, "fork");
		break;

	case 0:		/* child process */
		/* Execute with environment inherited from parent. */
		rc = execl("./environ-simple", "./environ-simple", NULL);
		DIE(rc < 0, "execl");

		return 0;

	default:	/* parent process: fall through */
		wait(NULL);
	}

	return 0;
}
