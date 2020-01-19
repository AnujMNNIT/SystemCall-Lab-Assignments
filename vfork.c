//yahan null pointer dereference ho rha hai
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
   int x=1;
   if(vfork()==0)
    {
         printf("mai child hun %d\n",++x);
    }
    else
    {
         printf("mai parent hun %d\n",--x);
    }
}
