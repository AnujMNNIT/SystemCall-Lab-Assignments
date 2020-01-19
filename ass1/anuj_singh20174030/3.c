#include<stdio.h>
int l=0;
int main(){
	//printf("L0\n");
	fork();
	//printf("L1\n");
	fork();
	//printf("L2\n");
	fork();
	printf("HELLO!\n");
	return 0;
}
