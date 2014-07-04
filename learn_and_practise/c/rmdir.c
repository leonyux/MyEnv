#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

void sigusr(int signo)
{
    printf("receive sigusr1\n");
}

int main(int argc, char **argv)
{
    errno = 0;
    signal(SIGUSR1, sigusr);
    if (mkdir("test", S_IRUSR | S_IWUSR | S_IXUSR) < 0)
    {
	printf("can not create directory: %s\n", strerror(errno));
	return -1;
    }
    DIR *dir;
    struct dirent *dirent;
    if ((dir = opendir("test")) == NULL)
    {
	printf("can not open directory: %s\n", strerror(errno));
	return -1;
    }
    printf("before rmdir:\n");
    while ((dirent = readdir(dir)) != NULL)
    {
	printf("%s\n", dirent->d_name);
    }
    pause();
    if (rmdir("test") < 0)
    {
	printf("rmdir failed: %s\n", strerror(errno));
	return -1;
    }
    pause();
    printf("after rmdir:\n");
    while ((dirent = readdir(dir)) != NULL)
    {
	printf("%s\n", dirent->d_name);
    }
    pause();
    if (closedir(dir) < 0)
    {
	printf("closedir failed: %s\n", strerror(errno));
	return -1;
    }
    printf("after closedir");
    if ((dir = opendir("test")) == NULL)
    {
	printf("can not open directory: %s\n", strerror(errno));
	return -1;
    }

}
