#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


extern int errno;

typedef void (Sigfunc) (int);
#define NUM_TO_READ 999999999

void alrm(int signo)
{
    printf("read timeout!\n");
}

Sigfunc *signal(int signo, Sigfunc * func)
{
    struct sigaction act, oact;
    printf("in my signal\n");
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM)
    {
#ifdef SA_INTERRUPT
	act.sa_flags |= SA_INTERRUPT;
	//act.sa_flags |= SA_RESTART;
	printf("SA_INTERRUPT configured\n");
#endif
    }
    else
    {
#ifdef SA_RESTART
	act.sa_flags |= SA_RESTART;
	printf("SA_RESTART configured\n");
#endif
    }
    if (sigaction(signo, &act, &oact) < 0)
	return (SIG_ERR);
    return (oact.sa_handler);
}

int main(void)
{
    int n = 0;
    char *line = 0;

    line = (char *) malloc(NUM_TO_READ);

    sigset_t set;

    if (signal(SIGALRM, alrm) == SIG_ERR)
	printf("set signal action error!\n");

    sigfillset(&set);
    sigdelset(&set, SIGALRM);

  loop:
    printf("set alarm!\n");
    alarm(3);

    if ((n = read(0, line, NUM_TO_READ)) < 0)
    {
	printf("read error! %d\n", n);
	printf("line: %s\n", line);
	//read(0, line, 1);
	//printf("aline: %s\n", line);
	goto loop;
    }
    else
	printf("%d char readed! errno %d %d\n", n, errno, EINTR);

//loop2:
//  if((n = read(0, line, NUM_TO_READ)) < 0) {
//    printf("read error! %d\n", n);
//    printf("line: %s\n", line);
//    //read(0, line, 1);
//    //printf("aline: %s\n", line);
//    goto loop2;
//  }
//  else
//    printf("%d char readed! errno %d %d\n", n, errno, EINTR);


    printf("start to write! %d\n", n);
    write(1, line, n);
    exit(0);
}
