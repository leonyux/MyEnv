#include <unistd.h>

int main(int argc, char **argv)
{
    int n = 0;
    char buf[10];
    while (read(0, buf, 1) != 0)
    {
	if (write(1, buf, 1) != 1)
	{
	    return -1;
	}
    }
    return 0;
}
