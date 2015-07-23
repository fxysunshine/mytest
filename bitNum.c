#include <stdio.h>

int bitNum(int num)
{
    int ret = 0;
    if (num < 0)
        return 0;

    while (num)
    {
        if (num % 2)
            ret++;
        num >>= 1;
    }    

    return ret;
}

int main()
{
    int num;
    printf("input the number: ");
    scanf("%d", &num);
    printf("the numbers of bit 1 in %d is:%d\n", num, bitNum(num));

    return 0;
}
