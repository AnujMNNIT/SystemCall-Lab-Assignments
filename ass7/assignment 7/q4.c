#include<stdio.h>
#include<signal.h>
void handler(int sig)
{
	signal(sig,SIG_IGN);
	signal(sig,SIG_IGN);
	signal(sig,SIG_IGN);
	signal(sig,SIG_IGN);
	switch(sig)
	{
		case SIGINT:
		printf("Interrupt handled\n");
		break;
		case SIGHUP:
		printf("Hangup handled\n");
		break;
		case SIGTERM:
		printf("Termination handled\n");
		break;
		case SIGQUIT:
		printf("Quit handled\n");
		exit(0);
		break;
	}
	signal(SIGINT,handler);
	signal(SIGHUP,handler);
	signal(SIGTERM,handler);
	signal(SIGQUIT,handler);
}

int main()
{
	pid_t pid=fork();
	if(pid==0)
	{
		printf("In child\n");
		signal(SIGINT,handler);
		signal(SIGHUP,handler);
		signal(SIGTERM,handler);
		signal(SIGQUIT,handler);
		while(1);
		
	}
	else
	{
		sleep(2);
		printf("In parent\n");
		kill(pid,SIGINT);
		sleep(2);
		kill(pid,SIGHUP);
		sleep(2);
		kill(pid,SIGTERM);
		sleep(2);
		kill(pid,SIGQUIT);
	}
}
