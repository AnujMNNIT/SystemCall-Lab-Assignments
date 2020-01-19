#include <pthread.h> 
#include <stdio.h> 
#include <math.h> 

int n = 0;
double ans[100];
int sq(void* arg)
{
	double temp = sqrt(n);
	ans[n]=temp;
	n++;
}

int main()
{
		pthread_t threads[100]; 
    int i;

    for (i=0; i<100; i++) { 
        int* p; 
        pthread_create(&threads[i], NULL, sq, NULL); 
    } 
   
    printf("Please wait while we are computing...\n");
    for (i=0;i<100;i++)  
        pthread_join(threads[i], NULL);
        
    for(i=0;i<100;i++)
    	printf("%d - %lf\n",i,ans[i]);
}
