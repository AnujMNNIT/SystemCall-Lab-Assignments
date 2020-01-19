#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	char *fifo="/tmp/2fifo";
	int fd=open(fifo,O_RDONLY);
	int i,j;
	int num[10];
	for(i=0;i<10;i++){
		read(fd,&num[i],sizeof(int));
		}
	close(fd);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(num[j]>num[j+1]){
				int temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
				}
			}
		}
	fd=open(fifo,O_WRONLY);
	for(i=0;i<10;i++){
		write(fd,&num[i],sizeof(int));
		}
	close(fd);
	return 0;
	
	}
