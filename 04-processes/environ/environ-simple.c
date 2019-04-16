#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *e;

	e = getenv("PATH");
	if (e == NULL)
		printf("PID %d (parent PID: %d): No environment variable named PATH.\n", getpid(), getppid());
	else
		printf("PID %d (parent PID: %d): PATH=%s\n", getpid(), getppid(), e);

	e = getenv("AUTHOR");
	if (e == NULL)
		printf("PID %d (parent PID: %d): No environment variable named AUTHOR.\n", getpid(), getppid());
	else
		printf("PID %d (parent PID: %d): AUTHOR=%s\n", getpid(), getppid(), e);

	return 0;
}
