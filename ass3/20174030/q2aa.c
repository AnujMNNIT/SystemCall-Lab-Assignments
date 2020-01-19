#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
int p[2];
pipe(p);
if(fork()>0)
{
	close(p[0]);
	//close(1);
	//dup(p[1]);
	dup2(p[1],1);
	close(p[1]);
	execlp("ls","ls",NULL);
}
else
{
	close(p[1]);
	//close(0);
	//dup(p[0]);
	dup2(p[0],0);
	close(p[0]);
	execlp("sort","sort",NULL);
	
}

}
