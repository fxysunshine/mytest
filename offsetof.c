#include <stdio.h>

#define offsetof(TYPE, MEMBER)     (size_t)&(((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({         \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);       \
    (type *)( (char *)__mptr - offsetof(type, member) );})

struct test_s
{
    int num;
    char ch;
    float f1;
};

int main()
{
    struct test_s s;
    struct test_s *p;
    printf("offsetof(struct test_s, num) = %ld\n", offsetof(struct test_s, num));
    printf("offsetof(struct test_s, ch) = %ld\n", offsetof(struct test_s, ch));
    printf("offsetof(struct test_s, f1) = %ld\n", offsetof(struct test_s, f1));
    printf("address of s = 0x%p\n", &s);
    p = container_of(&s.f1, struct test_s, f1);
    printf("address of s = 0x%p\n", p);
    printf("address of s = 0x%p\n", container_of(&s.ch, struct test_s, ch));

    return 0;
}
