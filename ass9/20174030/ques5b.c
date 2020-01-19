#include <pthread.h> 
#include <stdio.h> 

struct account{
	int balance;
}a;



int withdraw(void* p)
{
	a.balance-=600000;
}

int deposit(void* p)
{
	a.balance+=500000;
}

int main(){
	a.balance = 1000000;
	pthread_t threads[2];
	pthread_create(&threads[0], NULL, withdraw, NULL);
	//pthread_join(threads[0], NULL); 	
	pthread_create(&threads[1], NULL, deposit, NULL);
	//pthread_join(threads[1], NULL);
	printf("account balance after shiet = Rs%d\n",a.balance);
}



