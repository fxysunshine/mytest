#include <stdio.h>
#include <pthread.h>

int pthread_create (pthread_t *thread,
       const pthread_attr_t *attr,
       void *(*__start_routine) (void *),
       void *__arg) __attribute__ ((weak));

int main()
{
        if (pthread_create)
                printf("that is multi-thread version.\n");
        else
                printf("that is sigle thread version.\n");

        return 0;
}
