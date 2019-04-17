#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include "util.h"

#define NUM_THREADS		5

static __thread size_t age;
static pthread_key_t money_key;

static void bottom_fn(void)
{
	/* Read global variables. */
	printf("reading age in thread %lu\n", pthread_self());
	printf("age: %zu\n", age);
	printf("money: %zu\n", (size_t) pthread_getspecific(money_key));
}

static void *top_fn(void *arg)
{
	/* Initialize global variables. */
	printf("setting age and money in thread %lu\n", pthread_self());
	age = pthread_self();
	pthread_setspecific(money_key, (void *) pthread_self());

	/* Call the other function to read global variables. */
	bottom_fn();

	return NULL;
}

int main(void)
{
	pthread_t ths[NUM_THREADS];
	size_t i;
	int rc;

	rc = pthread_key_create(&money_key, NULL);
	DIE(rc < 0, "pthread_key_create");

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_create(&ths[i], NULL, &top_fn, NULL);
		DIE(rc < 0, "pthread_create");
	}

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(ths[i], NULL);
		DIE(rc < 0, "pthread_join");
	}

	return 0;
}
