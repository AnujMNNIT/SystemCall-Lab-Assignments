#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	char *fifo ="/tmp/fifo";
	int m = mkfifo(fifo,0666);
	int fd=open(fifo,O_RDONLY);
	char a[100];
	do{
		printf("Waiting...\n");
		read(fd,a,sizeof(a));
		printf("%s",a);
		printf("\n Done\n");
	}
	while(strcmp("Exit",a)!=0);
	printf("Exiting\n");
	close(fd);
	return 0;
	}
	
