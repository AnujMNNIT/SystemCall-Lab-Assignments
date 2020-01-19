#include<stdio.h>
#include<signal.h>
#include<math.h>
void handler(int sig)
{
	signal(SIGINT,SIG_IGN);
	signal(SIGHUP,SIG_IGN);
	signal(SIGTERM,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
	signal(SIGUSR1,SIG_IGN);
	switch(sig)
	{
		case SIGINT:
		printf("interrupt handled\n");
		break;
		case SIGHUP:
		printf("terminal hangup handled\n");
		break;
		case SIGTERM:
		printf("Termination handled\n");
		break;
		case SIGUSR1:
		printf("U got 1!!\n"); 
		break;
		case SIGQUIT:
		printf("Its time to quit\n");
		exit(0);
		break;
	}
	signal(SIGINT,handler);
	signal(SIGHUP,handler);
	signal(SIGTERM,handler);
	signal(SIGQUIT,handler);
	signal(SIGUSR1,handler);
}
		
int main()
{
	signal(SIGINT,handler);
	signal(SIGHUP,handler);
	signal(SIGTERM,handler);
	signal(SIGQUIT,handler);
	signal(SIGUSR1,handler);
	while(1){
		int b=rand()%10000000;
		if(b==1)
			raise(SIGUSR1);
	}		
}
