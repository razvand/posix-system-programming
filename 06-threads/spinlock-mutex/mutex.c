/*
 * Mutex vs Spinlock
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#include "util.h"

#define NUM_THREADS		2
#define NUM_ROUNDS		10000000


/* TODO: Define mutex/spinlock. */


pthread_barrier_t barrier;
static int shared = 0;


static inline void acquire_lock()
{
	/* TODO: Call mutex/spinlock acquire. */
}

static inline void release_lock()
{
	/* TODO: Call mutex/spinlock release. */
}

void *thread_func(void *arg)
{
	size_t i;

	pthread_barrier_wait(&barrier);

	for (i = 0; i < NUM_ROUNDS; i++)
	{
		acquire_lock();
		shared++;
		release_lock();
	}
	return NULL;
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	size_t i;
	int rc;

	/* TODO: Initialize mutex/spinlock. */

	pthread_barrier_init(&barrier, NULL, NUM_THREADS);

	for (i = 0; i < NUM_THREADS; i++){
		rc = pthread_create(&threads[i], NULL, thread_func, &i);
		DIE(rc == -1, "pthread_create");
	}

	for (i = 0; i < NUM_THREADS; i++){
		rc = pthread_join(threads[i], NULL);
		DIE(rc == -1, "pthread_join");
	}

	/* TODO: Destroy mutex/spinlock. */

	pthread_barrier_destroy(&barrier);

	return 0;
}
