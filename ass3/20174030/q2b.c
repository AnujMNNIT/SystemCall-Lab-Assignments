#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int c,char **arg){
	int i,j;
	int fd[2];
	pipe(fd);
	if(fork()==0){
		dup2(fd[1],1);
		close(fd[0]);close(fd[1]);
		execlp(arg[1],arg[1],arg[2],0);
	}
	else{
		dup2(fd[0],0);
		close(fd[0]);close(fd[1]);
		execlp(arg[3],arg[3],0);
	}
	return 0;
}
