#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char line[80];
    int n = 0;

    if ((n = read(0, line, 80)) < 0)
	printf("read error!\n");
    else
	printf("%d char readed!\n", n);
}
