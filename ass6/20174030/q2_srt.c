#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int fd;
	char *fifo = "/tmp/fifo";
	close(0);
	fd = open(fifo,O_RDONLY);
	char *args[]={"sort", NULL};
	execvp(args[0],args);
	close(fd);
	return 0;
}
