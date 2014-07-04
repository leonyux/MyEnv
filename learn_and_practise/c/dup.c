#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int arg, char **argv)
{
    int fd1 = 0;
    int fd2 = 0;
    off_t off = 0;
    char buf[20];
    fd1 = open("test", O_RDWR | O_CREAT | O_EXCL, S_IRWXU);
    fd2 = dup(fd1);
    printf("fd1=%d, fd2=%d\n", fd1, fd2);
    if (write(fd1, "hello world", 11) < 0)
    {
	printf("fd1 write failed\n");
    }
    close(fd1);
    printf("fd1=%d, fd2=%d\n", fd1, fd2);
    off = lseek(fd2, 0, SEEK_CUR);
    printf("fd2 offset is %ld\n", off);
    lseek(fd2, 0, SEEK_SET);

    read(fd2, buf, 11);
    buf[11] = 0;
    printf("%s\n", buf);
    off = lseek(fd2, 0, SEEK_CUR);
    printf("fd2 offset is %ld\n", off);
    close(fd2);
    return (0);
}
