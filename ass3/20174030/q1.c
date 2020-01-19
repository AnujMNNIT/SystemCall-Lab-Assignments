#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	char *str="Hello world";
	char st[100]; 
	int p[2];
	if(pipe(p)<0){
		exit(1);	
	}	
	if(fork()>0){
		printf("In parent process\n");
		close(p[0]);
                dup2(p[1],1);
		close(p[1]);
		execlp("ls","ls",NULL);
		printf("error");
		
	}
	else{	
		close(p[1]);
		printf("In child process\n");
		int fd=open("Hello.txt",O_WRONLY | O_CREAT | O_APPEND,0777);
		while(read(p[0],st,100)>0){
			printf("%d\n",write(fd,st,100));
		
		}
		close(p[0]);
		close(fd);
		
	}
return 0;
}
