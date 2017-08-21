#include <stdio.h>

unsigned long sp() {asm("mov %esp, %eax");}
int main()
{
	unsigned long esp = sp();
	printf("Stack pointer (ESP : 0x%lx)\n", esp);
	return 0;
}
