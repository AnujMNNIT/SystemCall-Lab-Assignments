#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	char *fifo ="/tmp/fifo";
	char a[100];
	int fd=open(fifo, O_WRONLY);
	do{
		printf("Enter input...");
		gets(a);
		printf("Writing\n");
		write(fd,a,sizeof(a));
		}
	while(strcmp("Exit",a)!=0);
	close(fd);
	return 0;
	
}	
		
	
