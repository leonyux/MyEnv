#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_stat(struct stat *stat)
{
    printf("ctime: %d\n", stat->st_ctime);
    return;
}

int main(int argc, char **argv)
{
    int fd;
    errno = 0;
    struct stat st;
    if ((fd = open("test_file", O_WRONLY | O_CREAT | O_EXCL, S_IRWXU)) < 0)
    {
	printf("can not creat file: %s\n", strerror(errno));
	errno = 0;
    }
    printf("stat file:\n");
    if (stat("test_file", &st) < 0)
    {
	printf("stat failed: %s\n", strerror(errno));
	errno = 0;
    }
    print_stat(&st);
    printf("fstat file:\n");
    if (fstat(fd, &st) < 0)
    {
	printf("fstat failed: %s\n", strerror(errno));
	errno = 0;
    }
    print_stat(&st);
    printf("link the file!\n");
    if (link("test_file", "test_file2") < 0)
    {
	printf("link failed: %s\n", strerror(errno));
	errno = 0;
    }
    printf("stat file:\n");
    if (stat("test_file", &st) < 0)
    {
	printf("stat failed: %s\n", strerror(errno));
	errno = 0;
    }
    print_stat(&st);
    printf("fstat file:\n");
    if (fstat(fd, &st) < 0)
    {
	printf("fstat failed: %s\n", strerror(errno));
	errno = 0;
    }
    print_stat(&st);
    printf("unlink the file2!\n");
    if (unlink("test_file2") < 0)
    {
	printf("unlink failed: %s\n", strerror(errno));
	errno = 0;
    }
    printf("stat file:\n");
    if (stat("test_file", &st) < 0)
    {
	printf("stat failed: %s\n", strerror(errno));
	errno = 0;
    }
    print_stat(&st);
    printf("fstat file:\n");
    if (fstat(fd, &st) < 0)
    {
	printf("fstat failed: %s\n", strerror(errno));
	errno = 0;
    }
    print_stat(&st);
    printf("unlink the file!\n");
    if (unlink("test_file") < 0)
    {
	printf("unlink failed: %s\n", strerror(errno));
	errno = 0;
    }
    printf("stat file:\n");
    if (stat("test_file", &st) < 0)
    {
	printf("stat failed: %s\n", strerror(errno));
	errno = 0;
    }
    print_stat(&st);
    printf("fstat file:\n");
    if (fstat(fd, &st) < 0)
    {
	printf("fstat failed: %s\n", strerror(errno));
	errno = 0;
    }
    print_stat(&st);
    printf("close file");
    close(fd);
}
