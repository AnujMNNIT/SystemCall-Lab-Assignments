#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

static int status=0;

void chldhandler(int sig)
{
	signal(sig,SIG_IGN);
	printf("In handler\n");
	printf("Exit status: %d\n",status);
	signal(SIGCHLD,chldhandler);
}



void chlhandler(int sig)
{
	signal(sig,SIG_IGN);
	printf("In the handler\n");
	signal(SIGINT,chlhandler);
}

int main()
{
	pid_t pid=fork();
	if(pid==0)
	{
		printf("In the child process\n");
		kill(getppid(),SIGINT);
		int a=5/0;
	}
	else
	{
		signal(SIGCHLD,chldhandler);
		signal(SIGINT,chlhandler);
		wait(&status);
	}
}
