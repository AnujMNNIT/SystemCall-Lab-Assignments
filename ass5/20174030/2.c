#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char *fifo="/tmp/2fifo";
	mkfifo(fifo,0666);
	int fd=open(fifo, O_WRONLY);
	int a[10];
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
		write(fd,&a[i],sizeof(int));
		}
	close(fd);
	fd=open(fifo, O_RDONLY);
	for(i=0;i<10;i++){
		read(fd,&a[i],sizeof(int));
		}
	close(fd);
	printf("Sorted Number\n");
	for(i=0;i<10;i++){
		printf("%d  ",a[i]);
		}
	return 0;
	}
