#include <stdio.h>

int main(int argc, char **argv)
{
    struct a
    {
	int b;
	int c;
    };

    struct a *x;
    printf("&a=%x\n", x);
    printf("&a.b=%x\n", &x->c);
}
