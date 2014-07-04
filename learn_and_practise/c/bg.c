#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char buf[1000] = { 0 };
    while (1)
    {
	scanf("a%sb", buf);
	printf("%s\n", buf);
	sleep(1);
    }
    return 0;
}
