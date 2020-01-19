#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int fd[2];
	pipe(fd);
	int x;
	if(fork()==0){
		printf("In child process\n");
		close(1);
		dup(fd[1]);
		close(fd[0]);close(fd[1]);
		execlp("ls","ls","-l",0);
	}
	else{	
		printf("In parent process\n");
		close(0);
		dup(fd[0]);
		close(fd[0]);close(fd[1]);
		execlp("sort","sort",0);
	}
	return 0;
}
