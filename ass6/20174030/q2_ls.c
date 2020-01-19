#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *fifo = "/tmp/fifo";
	mkfifo(fifo, 0666);
	open(fifo, O_WRONLY);
	char *args[]={"ls", "-l", NULL};
	execvp(args[0],args);
	return 0;
}
