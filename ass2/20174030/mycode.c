#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
   int i;
   for(i=1;i<=3;i++)
   {
      if(fork()==0)
      {
         if(i==1)
           execlp("ls","ls",0);
         else if(i==2)
           execlp("ps","ps",0);
         else if(i==3)
           execlp("who","who",0);
      }
      
   }
}
