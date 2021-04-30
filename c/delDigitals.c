
#include <stdio.h>

int delDigitals(char *str)
{
    int num = 0;
    char *fast, *slow;
    fast = slow = str;

    while (*fast)
    {
        if (*fast >= '0' && *fast <= '9') {
            fast++;
            num++;
        }
        else
            *slow++ = *fast++;
    }
    *slow = 0;
    return num;
}


int main()
{
    char str[256];
    printf("input the string(max len 255): ");
    scanf("%[^\n]", str);
    int num = delDigitals(str);
    printf("Del %d numbers in str:%s\n", num, str);

    return 0;
}
