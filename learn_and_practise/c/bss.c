#include <unistd.h>
#include <string.h>

int bss[1024 * 1024] = { 0 };

int main(int argc, char **argv)
{
    int i;
    for (i = 0; i < 1024 * 1024; i++)
    {
	bss[i] = 2;
    }
    pause();
    return 0;
}
