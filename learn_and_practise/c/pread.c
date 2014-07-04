#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int f = 0;
    ssize_t n = 0;
    off_t off = 0;
    char buf[10] = { };
    f = open("out", O_RDONLY);
    off = lseek(f, 0, SEEK_CUR);
    printf("current offset: %d\n", off);
    n = pread(f, buf, 10, 100);
    off = lseek(f, 0, SEEK_CUR);
    printf("current offset after pread: %d\n", off);
    n = read(f, buf, 10);
    off = lseek(f, 0, SEEK_CUR);
    printf("current offset after read: %d\n", off);

}
