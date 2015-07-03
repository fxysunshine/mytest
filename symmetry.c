#include <stdio.h>

int isSymmetryNum(int number)
{
    if (number < 0)
        return 0;

    int num, new_num;
    num = number;
    new_num = 0;

    while (num)
    {
        new_num = new_num * 10 + num % 10;
        num /= 10;
    }

    return (number == new_num);
}


int main()
{
    int num;
    printf("input the number:");
    scanf("%d", &num);
    if (isSymmetryNum(num))
        printf("%d is Symmetry number\n", num);
    else
        printf("%d is not Symmetry number\n", num);

    return 0;
}
