#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/*
Q2. 
1.No the print statement will not be executed because it will be replaced by the cp program and all content of PCB will be deleted except PID and pointers.
2.Shell is the parent.
3.just remove wait(0) in parent case.
4.-p means that the ownership,group info will be retained. -i means that the program will ask for confirmation before copying.
*/

int main(int argc,char *argv[])
{
    if(argc!=3)
    printf("Its an error\n");
    else{
        pid_t pid=fork();
        if(pid==0)
        {
            printf("for child process\n");
            printf("process id is %d\n",getpid());
            printf("parent process id is %d\n",getppid());
            printf("group process id is %d\n",getgid());
          //  execl("/bin/cp","-p","-i",argv[1],argv[2],0);
            char *args[]={"/bin/cp","-p","-i",argv[1],argv[2],0};
            execv(args[0],args);
            exit(0);
        }
        else if(pid<0)
        printf("Its an error damn\n");
        else
        {
            wait(1);
            printf("for parent process\n");
            printf("process id is %d\n",getpid());
            printf("parent process id is %d\n",getppid());
            printf("group process id is %d\n",getgid());
        }
    }
}
       
        
        
