#include <stdlib.h>
#include <stdio.h>

int main()
{
	void *A, *B, *C;

	A = malloc(0x100 - 8);
	B = malloc(0x100 - 8);
	C = malloc(0x80 - 8);
	printf("C chunk: %p -> %p\n", C, C + 0x80 - 8);

	free(B);
	*(char *)(A + 0x100 - 8) = 0x81;

	B = malloc(0x100 + 0x80 - 8);
	printf("new B chunk: %p -> %p\n", B, B + 0x100 + 0x80 - 8);

	return 0;
}
