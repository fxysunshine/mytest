//consolidate_forward.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 16

int main(int argc, char* argv[])
{
    if (argc != 2 ) {
        printf("usage: ./program arg1. Exiting...\n");
        exit(-1);
    }
        
    if (strlen(argv[1]) > 20) {
        printf("Buffer Overflow Attempt. Exiting...\n");
        exit(-2);
    }

    char* p2 = malloc(20);
    char* p3 = malloc(20);
    memset(p3, 1, 20);

    strcpy(p2,argv[1]);

    return 0;
}
