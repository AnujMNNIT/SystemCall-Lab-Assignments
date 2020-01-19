#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *fifo2 = "/tmp/fifo2";
	char *fifo1 = "/tmp/fifo1";
	mkfifo(fifo2, 0666);
	int pid = fork();
	if(pid != 0)
	{
		char ar[10];
		int fd = open(fifo2, O_WRONLY);
		fgets(ar, 10, stdin);
		write(fd, ar, strlen(ar)+1);
		close(fd);
	}
	else
	{
		char ar[10];
		int fd = open(fifo1, O_RDONLY);
		read(fd, ar, sizeof(ar));
		printf("read: %s\n", ar);
		close(fd);
	}
	return 0;
}
