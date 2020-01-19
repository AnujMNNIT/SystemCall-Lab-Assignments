#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int c,const char** argv)
{

        if(c!=2)
        {
                printf("Invalid number of arguments\n");
                exit(0);
        }
        int fd[2];
        if(pipe(fd)<0){
        	exit(1);
        }
        if(fork()==0)
        {
                close(0);
                char str[10];
                dup(fd[0]);
                close(fd[1]),close(fd[0]);
                scanf("%s",str);
                execlp("xterm","xterm","-e","man",str,0);
        }
        else
        {
                close(1);
                dup(fd[1]);
                close(fd[1]),close(fd[0]);
                printf("%s",argv[1]);
                
        }
        return 0;
}
