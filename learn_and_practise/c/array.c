#include <stdio.h>

int a[][20];
int b;
int c = 1;

void fun(int a[100][20])
{
    printf("a: %u\n", (unsigned int) a);
    printf("a+1: %u\n", (unsigned int) (a + 1));
    printf("a[0]: %u\n", (unsigned int) a[0]);
    printf("a[0]+1: %u\n", (unsigned int) (a[0] + 1));
    printf("&a: %u\n", (unsigned int) &a);
    printf("&a+1: %u\n", (unsigned int) (&a + 1));
    printf("sizeof(a): %u\n", sizeof(a));
}

int main(int argc, char **argv)
{
    fun(a);
    void *b;
    b = a;
    int *c;
    c = b;
    b = c;
    return 0;
}
