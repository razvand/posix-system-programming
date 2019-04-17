#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "util.h"

static unsigned int data_var = 0;

static void *inc(void *arg)
{
	data_var++;
	printf("data_var = %d\n", data_var);

	return NULL;
}

int main(void)
{
	pthread_t th;

	DIE(pthread_create(&th, NULL, &inc, NULL) != 0, "pthread_create");

	sleep(2);
	inc(NULL);

	DIE(pthread_join(th, NULL), "pthread_join");

	return 0;
}
