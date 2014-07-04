#include <stdio.h>

typedef enum E
{
    E1,
    E2
} E;

int main(int argc, char **argv)
{
    E i;
    i = (E) 32;
    printf("e: %d\n", i);
    return 0;
}
