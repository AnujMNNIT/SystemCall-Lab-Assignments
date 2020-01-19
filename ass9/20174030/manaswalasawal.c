#include<stdio.h>
#include<pthread.h>
int n=20;
void abcd( void *p)
{
  
  char a='A';
  printf("mai abcd\n");
  while(n--)
  {
  sleep(1);
  printf("%c\n",a++);
  }
}
void ginti( void *p)
{
  //int n=10;
   int a=1;
   printf("mai ginti");
  while(n--)
  {
  sleep(1);
  printf("%d\n",a++);
  }
}

int main()
{
  pthread_t t[2];
  printf("mai main process hun bro!\n");
  pthread_create(&t[0],NULL,abcd,NULL);
  pthread_create(&t[1],NULL,ginti,NULL);
  pthread_join(&t[0],NULL);
  pthread_join(&t[1],NULL);
  pthread_exit(0);
  
}
