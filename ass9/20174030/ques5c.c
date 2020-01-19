#include <pthread.h> 
#include <stdio.h> 

struct account{
	int balance;
}a;
pthread_mutex_t mut;
int withdraw(void* p)
{
 	pthread_mutex_lock(&mut);
	a.balance-=600000;
	pthread_mutex_unlock(&mut);
}

int deposit(void* p)
{
	pthread_mutex_lock(&mut);
	a.balance+=500000;
	pthread_mutex_unlock(&mut);
}

int main(){
	a.balance = 1000000;
	pthread_t thread[2];
	
	pthread_mutex_init(&mut,NULL);
        pthread_create(&thread[0], NULL, withdraw, NULL); 
	//pthread_join(thread, NULL); 	
	pthread_create(&thread[1], NULL, deposit, NULL);
	//pthread_join(thread[1], NULL);
	pthread_mutex_destroy(&mut);
	pthread_join(thread[0],NULL);
	pthread_join(thread[1],NULL);
	printf("account balance after shiet = Rs%d\n",a.balance);
}



