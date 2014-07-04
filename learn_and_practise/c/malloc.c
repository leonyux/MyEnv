#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char a[10];
    char *p = a;
    char *pp = malloc(10 * sizeof(char));
    free(a);
    //free(p);
    free(pp);
    return (0);
}
