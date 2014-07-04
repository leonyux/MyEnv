#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    printf("getpid: %d\n", getpid());
    exit(0);
}
