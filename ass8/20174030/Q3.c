#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	sigset_t sset,s2;
	sigemptyset(&sset);
	sigaddset(&sset,SIGINT);
	sigaddset(&sset,SIGHUP);
	sigaddset(&sset,SIGABRT);
	sigprocmask(SIG_SETMASK,&sset,NULL);
	kill(getpid(),SIGINT);
	kill(getpid(),SIGHUP);
	kill(getpid(),SIGABRT);
	sigpending(&s2);
	if(sigismember(&s2,SIGINT))
		printf("SIGINT is BLOCKED\n");
	if(sigismember(&s2,SIGHUP))
		printf("SIGHUP is BLOCKED\n");
	if(sigismember(&s2,SIGABRT))
		printf("SIGABRT is BLOCKED\n");
	return 0;
}
