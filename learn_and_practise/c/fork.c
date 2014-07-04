#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd = 0;
    errno = 0;
    char buf[10] = { };
    int n = 0;
    if ((fd = open("test", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) < 0)
    {
	printf("open failed: %s\n", strerror(errno));
	return -1;
    }
    printf("fd=%d\n", fd);
    if (write(fd, "hello world", 11) < 0)
    {
	printf("write failed: %s\n", strerror(errno));
	return -1;
    }
    if (lseek(fd, 0, SEEK_SET) < 0)
    {
	printf("lseek failed: %s\n", strerror(errno));
	return -2;
    }
    if ((n = read(fd, buf, 5)) < 0)
    {
	printf("read failed: %s\n", strerror(errno));
	return -3;
    }
    else
    {
	printf("%d char readed: %s\n", n, buf);
    }
    if ((n = lseek(fd, 0, SEEK_CUR)) < 0)
    {
	printf("lseek failed: %s\n", strerror(errno));
	return -2;
    }
    else
    {
	printf("current off: %d\n", n);
    }
    if (fork() == 0)
    {
	if (lseek(fd, 2, SEEK_SET) < 0)
	{
	    printf("child lseek failed: %s\n", strerror(errno));
	    return -2;
	}
	if ((n = lseek(fd, 0, SEEK_CUR)) < 0)
	{
	    printf("child lseek failed: %s\n", strerror(errno));
	    return -2;
	}
	else
	{
	    printf("child current off: %d\n", n);
	}
	close(fd);
	exit(0);
    }
    else
    {
	sleep(3);
	if ((n = lseek(fd, 0, SEEK_CUR)) < 0)
	{
	    printf("parent lseek failed: %s\n", strerror(errno));
	    return -2;
	}
	else
	{
	    printf("parent current off: %d\n", n);
	}
	if ((n = read(fd, buf, 6)) < 0)
	{
	    printf("parent read failed: %s\n", strerror(errno));
	    return -3;
	}
	else
	{
	    printf("parent %d char readed: %s\n", n, buf);
	}
	close(fd);
	exit(0);
    }
    return (0);
}
