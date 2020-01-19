#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<assert.h>
void  myHandler(int sig)
{
    signal(SIGINT,SIG_IGN);
    int n=7;
    while(n--)
     {
        sleep(1);
        printf("I AM SIGINT\n");
     }
    signal(SIGINT,myHandler);
}

int main(void) {
   int iRet;
   sigset_t s;
   struct sigaction sAction;
   sAction.sa_flags = 0;
   sAction.sa_handler = myHandler;
   sigemptyset(&s);
   sigaddset(&s,SIGINT);
   iRet = sigaction(SIGINT, &sAction, NULL);
   assert(iRet == 0);
   int cnt=8;
   sigprocmask(SIG_BLOCK,&s,NULL);
   while(cnt--)
   {
     printf("I am in loop\n");
     sleep(1);
   }
  sigprocmask(SIG_UNBLOCK,&s,NULL);
   sigset_t pending;
   sigpending(&pending);
   if(sigismember(&pending,SIGINT))
   {
      printf("User tried to interrupt\n"); 
   }
   else if(sigismember(&pending,SIGILL))
   {
     printf("user tried to do  illogical math\n");
   }
    
   return 0;
}

