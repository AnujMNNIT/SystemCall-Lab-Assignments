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
unlink("fifo1");
mkfifo("fifo1",0777);
while(1){
int fd1=open("fifo1",O_WRONLY);
char str[50],str1[50];
//scanf("%s",str);
fgets(str,50,stdin);
write(fd1,str,50);
close(fd1);
int fd2=open("fifo2",O_RDONLY);
read(fd2,str1,50);
printf("%s",str1);
close(fd2);

}



}

