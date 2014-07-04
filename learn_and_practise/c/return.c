#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int func(int arg)
{
    printf("in func arg=%d\n", arg);
    return (arg);
}

void exit_func(void)
{
    printf("exit_func\n");
}

int main(int argc, char **argv)
{
    int i = 2;
    printf("in main\n");
    i = func(i);
    printf("func return %d add\n", i);
//    if (atexit(exit_func) != 0)
//    {
//        printf("atexit failed\n");
//    }
//    for (i = 0; environ[i] != NULL; i++)
//    {
//        printf("%s\n", environ[i]);
//    }
}
