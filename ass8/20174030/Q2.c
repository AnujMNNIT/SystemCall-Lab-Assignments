//rs, while the signal handler is busy processing a
//signal .

#include<stdio.h>
#include<signal.h>

int cpid;
sigset_t sSet;

void childhandler(int sig){
    sigemptyset(&sSet);int iRet;
     sigaddset(&sSet, sig);
     iRet = sigprocmask(SIG_BLOCK, &sSet, NULL);
   
    printf("%d",sig);
    printf("Signal number %d recieved\n",sig);
    if(sig==SIGQUIT){
        exit(0);
    }
    sleep(5000);
    iRet = sigprocmask(SIG_UNBLOCK, &sSet, NULL);
}

void parenthandler(int sig){
     sigemptyset(&sSet);
     int iRet;
     sigaddset(&sSet, sig);
     iRet = sigprocmask(SIG_BLOCK, &sSet, NULL);
    kill(cpid,sig);
    if(sig==SIGQUIT){
        exit(0);
    }
    sleep(5000);
    iRet = sigprocmask(SIG_UNBLOCK, &sSet, NULL);
}

int main(void){
    pid_t pid=fork();
    if(pid==0){
        int i;
        for(i=1;i<33;i++)
        if( signal(i,SIG_IGN)!=SIG_IGN){
            int iret;
            struct sigaction sAction;
            sAction.sa_flags = 0;
            sAction.sa_handler = childhandler;
            sigemptyset(&sAction.sa_mask);
            iret=sigaction(i,&sAction,NULL);
         }
        while(1)
        	pause();
    }
    else{
        cpid=pid;
        int i;
        for(i=1;i<33;i++)
        if( signal(i,SIG_IGN)!=SIG_IGN){
            int iret;
            struct sigaction sAction;
            sAction.sa_flags = 0;
            sAction.sa_handler = parenthandler;
            sigemptyset(&sAction.sa_mask);
            iret=sigaction(i,&sAction,NULL);
         }
         while(1)
        pause();
    }
       
}
