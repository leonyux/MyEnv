#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd;
    int len = 0;
    fd = open("test", O_RDWR | O_CREAT, S_IRWXU);
    if (fd < 0)
    {
	printf("open error\n");
	return (-1);
    }
    getchar();
    if ((write(fd, argv[1], len = strlen(argv[1]))) < len)
    {
	printf("write error\n");
	return (-1);
    }
    getchar();
    close(fd);
    return (0);
}
