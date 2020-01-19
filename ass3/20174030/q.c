#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


int main()
{

int p1[2];
pipe(p1);

if(fork()>0){
	close(p1[0]);
	dup2(p1[1],1);
	close(p1[1]);
	execlp("ls","ls","-l",0);
}

else{
int p2[2];
pipe(p2);
	close(p1[1]);
	dup2(p1[0],0);
	close(p1[0]);

if(fork()>0){
	
	//sleep(2);
	close(p2[0]);
	dup2(p2[1],1);
	close(p2[1]);
       // char str[10]="myMan.c";
	execlp("sort","sort",0);

}

else
{
	close(p2[1]);
	dup2(p2[0],0);
	close(p2[0]);
	execlp("wc","wc",0);	
}

}
}
