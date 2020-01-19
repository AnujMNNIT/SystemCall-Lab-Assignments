#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    printf("Error\n");
    else if(pid==0)
    {
        char *arg[]={"/bin/ps",0};
        execv(arg[0],arg);
        exit(0);
    }
    else
    {
        char *arg[]={"/bin/ls","-l",0};
        execv(arg[0],arg);
        exit(0);
    }
}
