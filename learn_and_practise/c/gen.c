#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_TO_READ 999999999

int main(int argc, char **args)
{
    //char line[10] = "abcdefghij";
    //char *out = line;
    char *line = 0;
    line = (char *) malloc(NUM_TO_READ);
    if (1)
    {
	//write(1, (out - line) < 10 ? out++ : (out = line, out ++), 1);
	sleep(2);
	write(1, line, NUM_TO_READ);
	printf("write complete\n");
    }
}
