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
		int fd;
		char *fifo1 = "/tmp/fifos21";
		char *fifo2 = "/tmp/fifoc12";
		mkfifo(fifo2, 0666);
		char arr1[100], arr2[100];
		int pid = fork();
		if(pid == 0)
		{
			fd = open(fifo1, O_RDONLY);
			read(fd, arr1, sizeof(arr1));
			printf("got: %s\n", arr1);
			close(fd);
		}
		else
		{
			fd = open(fifo2, O_WRONLY);
			fgets(arr2, 100, stdin);
			write(fd, arr2, strlen(arr2)+1);
			close(fd);
		}
	}
}
