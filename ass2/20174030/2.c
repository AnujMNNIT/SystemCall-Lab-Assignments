#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    printf("ERROR\n");
    else if(pid==0)
    {
        char *arg[]={"/bin/ls","-l",0};
        execv(arg[0],arg);
    }
    else
    {
        int status;
        wait(&status);
        if(WIFEXITED(status))
        {
            printf("exit status of child process is %d\n",WEXITSTATUS(status));
        }
    }
}
