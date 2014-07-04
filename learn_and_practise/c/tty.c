#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *name;
    FILE *fp = NULL;
    name = ctermid(NULL);
    fp = fopen(name, "r+");
    setbuf(fp, NULL);
    if (fp == NULL)
    {
	return -1;
    }
    sleep(2);
    fprintf(fp, "tty: %s %d\n", name, fileno(fp));
    printf("tty: %s %d\n", name, fileno(fp));
    return 0;
}
