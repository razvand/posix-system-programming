#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "util.h"

int main(void)
{
	pid_t pid;
	int status;

	pid = fork();
	switch (pid) {
	case -1:	/* error */
		DIE(pid == -1, "fork");

	case 0:		/* child process */
		printf("  [child] New process created. PPID is %d.\n", getppid());
		printf("  [child] Exec-ing ls -l\n");
		execl("/bin/ls", "ls", "-l", NULL);
		break;

	default:	/* parent process */
		break;
	}

	/* Wait for the child process then exit. */
	waitpid(pid, &status, 0);
	printf("  [parent] Child exited with exit code %d.\n", status);

	return 0;
}
