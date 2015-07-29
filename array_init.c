#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <malloc.h>

typedef int64_t usecs_t;

usecs_t systemTime()
{
    struct timeval t;
    t.tv_sec = t.tv_usec = 0;
    gettimeofday(&t, NULL);
    return ((usecs_t)t.tv_sec)*1000000LL + (usecs_t)t.tv_usec;
}

void memfill(void *dest, size_t destsize, size_t elemsize)
{
    char *nextdest = (char *)dest + elemsize;
    size_t movesize, donesize = elemsize;

    destsize -= elemsize;

    while (destsize) {
        movesize = (donesize < destsize) ? donesize : destsize;
        memcpy(nextdest, dest, movesize);
        nextdest += movesize;
        destsize -= movesize;
        donesize += movesize;
    }
}

#define ARRAY_NUM 1000000
int main()
{
    int i;
    int *a = (int *)malloc(ARRAY_NUM*sizeof(int));
    int *b = (int *)malloc(ARRAY_NUM*sizeof(int));
    usecs_t startTime;

    startTime = systemTime();
    for (i=0; i<ARRAY_NUM; i++)
        b[i] = 10;
    printf("arrar for  init time %ums\n", (unsigned)((systemTime() - startTime) / 1000));

    startTime = systemTime();
    a[0] = 10;
    memfill(a, ARRAY_NUM*sizeof(int), sizeof(int));
    printf("array fast init time %ums\n", (unsigned)((systemTime() - startTime) / 1000));

    return 0;
}
