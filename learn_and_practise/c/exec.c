#include <unistd.h>

int main(int argc, char **argv)
{
    if (execl("./bss", "bss", (char *) 0) != 0)
    {
	return -1;
    }
    return 0;
}
