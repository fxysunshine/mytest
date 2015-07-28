#include <stdio.h>

#define offsetof(TYPE, MEMBER)     (size_t)&(((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({         \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);       \
    (type *)( (char *)__mptr - offsetof(type, member) );})

struct foo
{
    char ch;
    int num;
    float bar;
};

int main()
{
    struct foo f;
    struct foo *p;
    char *a;
    char *b;
    printf("offsetof(struct foo, ch) = %ld\n", offsetof(struct foo, ch));
    printf("offsetof(struct foo, num) = %ld\n", offsetof(struct foo, num));
    printf("offsetof(struct foo, bar) = %ld\n", offsetof(struct foo, bar));
    printf("address of f = 0x%p\n", &f);
    p = container_of(&f.bar, struct foo, bar);
    printf("address of f = 0x%p\n", p);
    printf("address of f = 0x%p\n", container_of(&f.num, struct foo, num));

    a = (char *)&f.bar;
    b = (char *)&f + offsetof(struct foo, bar);
    printf("address of a = 0x%p b = 0x%p\n", a, b);

    return 0;
}
