#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned int a = 0x12345678;
    unsigned int b = a;
    b |= 0;
    printf("0x%x\n", b);
    b |= 0x0 | 0x1;
    printf("0x%x\n", b);
    return 0;
}
