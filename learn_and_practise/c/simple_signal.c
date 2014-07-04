#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

typedef void (Sigfunc) (int);

jmp_buf env;

Sigfunc *signal(int signo, Sigfunc * func)
{
    printf("custom signal!\n");
    struct sigaction act, oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM)
    {
#ifdef SA_INTERRUPT
	act.sa_flags |= SA_INTERRUPT;
#endif
    }
    else
    {
#ifdef SA_RESTART
	act.sa_flags |= SA_RESTART;
#endif
    }
    if (sigaction(signo, &act, &oact) < 0)
	return (SIG_ERR);
    return (oact.sa_handler);
}

static void sig_usr(int);
int main(int argc, char **argv)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
	printf("can't catch SIGUSR1\n");
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
	printf("can't catch SIGUSR2\n");
    for (;;)
    {
	if (setjmp(env) == 0)
	{
	    pause();
	}
	sigset_t sig;
	sigprocmask(SIG_BLOCK, 0, &sig);
	if (!sigismember(&sig, SIGUSR1))
	    printf("SIGUSR1 unmasked!\n");
	else
	    printf("SIGUSR1 still masked!\n");
	if (!sigismember(&sig, SIGUSR2))
	    printf("SIGUSR2 unmasked!\n");
	else
	    printf("SIGUSR2 still masked!\n");
    }
}

static void sig_usr(int signo)
{
    sigset_t sig;
    sigprocmask(SIG_BLOCK, 0, &sig);
    if (sigismember(&sig, SIGUSR1))
	printf("SIGUSR1 masked!\n");
    if (sigismember(&sig, SIGUSR2))
	printf("SIGUSR2 masked!\n");
    if (signo == SIGUSR1)
	printf("received SIGUSR1\n");
    else if (signo == SIGUSR2)
	printf("received SIGUSR2\n");
    else
	printf("received signal:%d\n", signo);
    longjmp(env, 1);
}
