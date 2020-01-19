#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	while(1)
	{
		int fd11, fd12, fd21, fd22;
		char *fifo11 = "/tmp/fifos21";
		char *fifo12 = "/tmp/fifos22";
		char *fifo21 = "/tmp/fifoc12";
		char *fifo22 = "/tmp/fifoc22";
		mkfifo(fifo11, 0666);
		mkfifo(fifo12, 0666);
		char arr1[100];
		fd11 = open(fifo11, O_WRONLY);
		fd12 = open(fifo12, O_WRONLY);
		fd21 = open(fifo21, O_RDONLY);
		fd22 = open(fifo22, O_RDONLY);
		int pid = fork();
		if(pid == 0)
		{
			int s = read(fd21, arr1, sizeof(arr1));	
			arr1[s-2] = '\0';
			printf("client 1: %s\n", arr1);
			write(fd12, arr1, strlen(arr1)+1);
		}
		else
		{
			int s = read(fd22, arr1, sizeof(arr1));
			arr1[s-2] = '\0';
			printf("client 2: %s\n", siz, arr1);
			write(fd11, arr1, strlen(arr1)+1);
		}
		close(fd11);
		close(fd21);
		close(fd12);
		close(fd22);
	}
}
