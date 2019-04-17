#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "util.h"

static int data_var = 0;

static void inc(void)
{
	data_var++;
	printf("data_var = %d\n", data_var);
}

int main(void)
{
	int status;
	pid_t pid;

	pid = fork();
	DIE(pid, "fork");
	switch (pid) {
	case 0:
		/* child process */
		inc();
		break;
	default:
		/* parent process */
		sleep(2);
		inc();
		wait(&status);
		break;
	}

	return 0;
}
