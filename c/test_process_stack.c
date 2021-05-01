#include <stdio.h>

int main()
{
    int i = 0;
    int a[1000];
    int b[10 * 1000];
    int c[100 * 1000];
    int d[1000 * 1000];

    printf("bingo\n");
    printf("i:%p, a:%p, b:%p, c:%p, d:%p", &i, a, b, c, d);
    return 0;
}
