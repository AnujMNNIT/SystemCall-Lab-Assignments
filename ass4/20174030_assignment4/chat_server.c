#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<signal.h>

int main()
{
unlink("fifo2");
mkfifo("fifo2",0777);
while(1){
char str[50];
int fd1=open("fifo1",O_RDONLY);
read(fd1,str,50);
printf("%s",str);
close(fd1);
int fd2=open("fifo2",O_WRONLY);
char str1[50];
//scanf("%s",str1);
fgets(str1,50,stdin);
write(fd2,str1,50);
close(fd2);
}
}

