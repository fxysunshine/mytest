#include <stdio.h>

int isSymmetryNum(int number)
{
    if (number < 0)
        return 0;

    int ori_num, new_num;
    ori_num = number;
    new_num = 0;

    while (number)
    {
        new_num = new_num * 10 + number % 10;
        number /= 10;
    }

    return (ori_num == new_num);
}

int main()
{
    int num;
    printf("input the number:");
    if (scanf("%d", &num) < 0) {
      printf("scanf failed\n");
    }
    if (isSymmetryNum(num))
        printf("%d is Symmetry number\n", num);
    else
        printf("%d is not Symmetry number\n", num);

    return 0;
}
