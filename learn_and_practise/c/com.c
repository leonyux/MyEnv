#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned short us;
    int i = -1;
    us = i;
    printf("us %d, i %d\n", us, i);
    if (i == us)
    {
	printf("equal\n");
    }
    else
    {
	printf("not equal\n");
    }
    return 0;
}
