#include<stdio.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	int i=0;
	for(i=1;i<=5;i++)
	{
		if(fork()>0)
		{
			printf("Child  %d WITH PID %d is created from parent %d\n",i,getpid(),getppid());
			exit(0);
		}
	}
}	
