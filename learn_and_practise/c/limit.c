#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **args)
{
    long max = 0;
    printf("NAME_MAX=%d\n", _XOPEN_NAME_MAX);
    max = pathconf("/", _PC_NAME_MAX);
    printf("_PC_NAME_MAX=%d\n", max);
}
