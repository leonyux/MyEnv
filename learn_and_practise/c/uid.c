#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    printf("current uid=%d, euid=%d\n", getuid(), geteuid());
    printf("seteuid(300):\n");
    if (seteuid(300) < 0)
    {
	printf("setreuid failed: %s\n", strerror(errno));
    }
    printf("current uid=%d, euid=%d\n", getuid(), geteuid());
    printf("seteuid(0):\n");
    if (seteuid(0) < 0)
    {
	printf("setreuid failed: %s\n", strerror(errno));
    }
    printf("current uid=%d, euid=%d\n", getuid(), geteuid());
    printf("seteuid(300):\n");
    if (seteuid(300) < 0)
    {
	printf("setreuid failed: %s\n", strerror(errno));
    }
    printf("current uid=%d, euid=%d\n", getuid(), geteuid());
    printf("setreuid(-1, 300):\n");
    if (setreuid(-1, 300) < 0)
    {
	printf("setreuid failed: %s\n", strerror(errno));
    }
    printf("current uid=%d, euid=%d\n", getuid(), geteuid());
    printf("seteuid(0):\n");
    if (seteuid(0) < 0)
    {
	printf("setreuid failed: %s\n", strerror(errno));
    }
    printf("current uid=%d, euid=%d\n", getuid(), geteuid());
    return (0);
}
