#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    struct stat tty, fd0, fd1;
    stat("/dev/tty", &tty);
    fstat(0, &fd0);
    fstat(1, &fd1);
    printf("tty: inode: %ld, dev: M:%d m:%d, real: %ld\n", tty.st_ino,
	   major(tty.st_dev), minor(tty.st_dev), tty.st_rdev);
    printf("fd0: inode: %ld, dev: M:%d m:%d, real: %ld\n", fd0.st_ino,
	   major(fd0.st_dev), minor(fd0.st_dev), fd0.st_rdev);
    printf("fd1: inode: %ld, dev: M:%d m:%d, real: %ld\n", fd1.st_ino,
	   major(fd1.st_dev), minor(fd1.st_dev), fd1.st_rdev);
    printf("fd0: %d\n", isatty(0) ? 1 : 0);
    printf("fd1: %d\n", isatty(1) ? 1 : 0);
    printf("fd0 ttyname: %s\n", ttyname(0));
    printf("fd1 ttyname: %s\n", ttyname(1));
    printf("ctermid: %s\n", ctermid(NULL));
    stat(ttyname(0), &fd0);
    stat(ttyname(1), &fd1);
    printf("fd0: inode: %ld, dev: M:%d m:%d, real: %ld\n", fd0.st_ino,
	   major(fd0.st_dev), minor(fd0.st_dev), fd0.st_rdev);
    printf("fd1: inode: %ld, dev: M:%d m:%d, real: %ld\n", fd1.st_ino,
	   major(fd1.st_dev), minor(fd1.st_dev), fd1.st_rdev);
    printf("fd0: %d\n", isatty(0) ? 1 : 0);
    printf("fd1: %d\n", isatty(1) ? 1 : 0);
    return 0;
}
