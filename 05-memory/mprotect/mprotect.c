#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#include "util.h"

/* Byte string shellcode for printing "Hello, World!" */
static char shellcode[] = "\x68\x21\x0a\x00\x00\x68\x6f\x72\x6c"
				 "\x64\x68\x6f\x2c\x20\x57\x68\x48\x65"
				 "\x6c\x6c\xba\x0e\x00\x00\x00\x89\xe1"
				 "\xbb\x01\x00\x00\x00\xb8\x04\x00\x00"
				 "\x00\xcd\x80\xbb\x00\x00\x00\x00\xb8"
				 "\x01\x00\x00\x00\xcd\x80";

int main(void)
{
	void (*func_ptr)(void) = (void (*)(void)) shellcode;
#if 1
	size_t page_size = sysconf(_SC_PAGE_SIZE);
	void *map_address;
	int rc;

	map_address = (void *) ((((unsigned long) shellcode) / page_size) * page_size);
	printf("shellcode address: %p, map_address: %p\n", shellcode, map_address);
	rc = mprotect(map_address, page_size, PROT_READ | PROT_WRITE | PROT_EXEC);
	DIE(rc < 0, "mprotect");
#endif

	/* Call shellcode. */
	func_ptr();

	return 0;
}
