#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd1, fd2, fd3;
	char *fifo1 = "/tmp/fifo1";
	char *fifo2 = "/tmp/fifo2";
	mkfifo(fifo1, 0666);
	fd1 = open(fifo1, O_WRONLY);
	fd2 = open(fifo2, O_RDONLY);
	char ar1[10];
	int siz = read(fd2, ar1, sizeof(ar1));
	ar1[siz-2] = '\0';
	fd3 = open(ar1, O_RDONLY);
	char ar2[10];
	int size = read(fd3, ar2, 10);
	ar2[size] = '\0';
	printf("Sent\n");
	write(fd1, ar2, strlen(ar2)+1);
	close(fd2);
	close(fd3);
	close(fd1);
	return 0;
}
