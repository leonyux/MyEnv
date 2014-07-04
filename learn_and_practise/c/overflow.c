#include <stdio.h>

int main(int argc, char **argv)
{
    int a;
    long b;
    short c;
    unsigned short d;
    printf("sizeof int: %d\n", sizeof(a));
    printf("sizeof long: %d\n", sizeof(b));
    printf("sizeof short: %d\n", sizeof(c));
    printf("sizeof unsigned short: %d\n", sizeof(d));
    a = 0xffffffff;
    printf("a=%d\n", a);
    c = a;
    printf("c=%d\n", c);
    d = a;
    printf("d=%d\n", d);
    return (0);
}
