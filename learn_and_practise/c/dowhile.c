#include <stdio.h>

#define func(x) do {\
    printf("in func:\n");\
    switch (x)\
    {\
	case 1:\
	    printf("one\n");\
	    break;\
	case 2:\
	    printf("two\n");\
	    break;\
	default:\
	    printf("sorry: %d\n", x);\
	    break;\
    }\
} while (0)

int main(void)
{
    char a = 0;
    int b = 0;
    printf("into loop:\n");
    while (1)
    {
	a = getchar();
	printf("a=%d b=%d\n", a, b);
	b = a - 48;
	func(b);
    }
}
