#include <stdio.h>

int main()
{
    int a[3] = {1, 2, 3};
    int *p = a;
    int **r = &p;
    int ***q = &r;
    printf("*q:%p q:%p *r:%p r:%p a:%p\n", *q, q, *r, r, a);

    return 0;
}
