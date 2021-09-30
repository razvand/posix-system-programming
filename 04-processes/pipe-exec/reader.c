#include <stdio.h>

int main(void)
{
	char buffer[128];

	fgets(buffer, 128, stdin);
	fprintf(stderr, "read: I read %s\n", buffer);
}
