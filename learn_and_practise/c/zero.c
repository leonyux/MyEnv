#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv)
{
    int fd;
    char buf[10];
    fd = open("/dev/zero", O_RDWR);
    if (lseek(fd, 0, SEEK_SET) != 0)
    {
	printf("lseek error!\n");
	return -1;
    }
    write(fd, "1", 1);
    if (lseek(fd, 0, SEEK_SET) != 0)
    {
	printf("lseek error!\n");
	return -1;
    }
    read(fd, buf, 1);
    buf[1] = 0;
    printf(buf);
    printf("end\n");
    return 0;
}
