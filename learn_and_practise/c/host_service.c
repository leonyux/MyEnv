#include <netdb.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    struct hostent *host;
    char **index;
    while ((host = gethostent()) != NULL)
    {
	printf("hostname: %s\n", host->h_name);
	index = host->h_aliases;
	while (*index != NULL)
	{
	    printf("    alternative hostname: %s\n", *index);
	    index++;
	}
    }
    return 0;
}
