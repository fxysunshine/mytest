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
        
    if (strlen(argv[1]) > 1020) { /* [1] */
        printf("Buffer Overflow Attempt. Exiting...\n");
        exit(-2);
    }

    char* tmp = malloc(20-4); /* [2] */
    char* p = malloc(1024-4); /* [3] */
    char* p2 = malloc(1024-4); /* [4] */
    char* p3 = malloc(1024-4); /* [5] */

    strcpy(p2,argv[1]); /* [6] */

    free(p); /* [7] */

    return 0;
}
