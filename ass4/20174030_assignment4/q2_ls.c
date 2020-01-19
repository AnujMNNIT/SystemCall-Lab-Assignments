#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	close(1);
	char *fifo = "/tmp/fifo";
	mkfifo(fifo, 0666);
	int fd=open(fifo, O_WRONLY);
	char *args[]={"ls", "-l", NULL};
	execvp(args[0],args);
	close(fd);
	return 0;
}
