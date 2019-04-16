#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static unsigned int init_array[256*1024] = {1, };

static unsigned int non_init_array[1024*1024];

int main(void)
{
	printf("init_array[100]: %u\n", init_array[100]);
	printf("non_init_array[100]: %u\n", non_init_array[100]);

	sleep(100);

	return 0;
}
