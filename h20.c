#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int hydrogen=0;
int oxygen=0;
int water=0;
pthread_mutex_t mut;
void* hReady(void *p)
{
   pthread_mutex_lock(&mut);
   printf("I am hydrogen\n");
   hydrogen++;
   pthread_mutex_unlock(&mut);
}
void* oReady(void* q)
{
   pthread_mutex_lock(&mut);
   printf("I am oxygen\n");
   oxygen++;
   pthread_mutex_unlock(&mut);
}
void* makeWater(void *h)
{
   pthread_mutex_lock(&mut);
   if(oxygen>=1&&hydrogen>=2)
{
   printf("one drop of water is made\n");
   hydrogen=hydrogen-2;
   oxygen=oxygen-1;
   water++;
}
   pthread_mutex_unlock(&mut);
}

int main()
{
  pthread_t thread[1000];
  int cnt=0;
  pthread_mutex_init(&mut,NULL);
  while(1)
  {
     sleep(1);
     cnt++;
     if(cnt%2==0)
     {
        int n=rand()%2;
        if(n==0)
              pthread_create(&thread[cnt],NULL,hReady,NULL);
        else
              pthread_create(&thread[cnt],NULL,oReady,NULL);
     }
     else
     {
              pthread_create(&thread[cnt],NULL,makeWater,NULL);
     }
  }
  pthread_mutex_destroy(&mut);

}
