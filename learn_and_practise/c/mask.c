#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char a[10] = { };
    int n = 0;

    while (1)
    {
	if ((n = read(0, a, 10)) < 0)
	{
	    printf("read error!\n");
	    continue;
	}
	n = atoi(a);
	printf("n: %d, n&3: %#d\n", n, (n & 3));
    }
}
