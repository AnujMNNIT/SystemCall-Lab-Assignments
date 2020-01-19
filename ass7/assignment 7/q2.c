#include<stdio.h>
#include<signal.h>
#include<string.h>

void alarmhandler(int sig)
{
	signal(SIGALRM,SIG_IGN);
	printf("alarm signal received\n");
	signal(SIGALRM,alarmhandler);
}

int main(int argc,char *argv[])
{
	long sum=5;
	signal(SIGALRM,alarmhandler);
	int SECOND=abs(atoi(argv[1]));
	alarm(2);
	while(sum--){		
	sleep(2);
	alarm(2);
	}
}
