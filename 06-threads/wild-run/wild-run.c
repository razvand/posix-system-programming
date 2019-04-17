#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "util.h"

#define NUM_THREADS		16

static void *thread_fn(void *arg)
{
	/* Useless CPU consumption. */
	size_t i, j;
	size_t val = 0x12345678;

	for (i = 0; i < 10000000; i++) {
		val = val ^ i;
		for (j = 0; j < 300; j++)
			val = val ^ j;
	}

	return NULL;
}

int main(void)
{
	pthread_t ths[NUM_THREADS];
	size_t i;
	int rc;

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_create(&ths[i], NULL, &thread_fn, NULL);
		DIE(rc < 0, "pthread_create");
	}

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(ths[i], NULL);
		DIE(rc < 0, "pthread_join");
	}

	return 0;
}
