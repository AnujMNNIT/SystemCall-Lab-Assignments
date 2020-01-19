#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  char str[100];
  int fd,fd2,fd3;
  fd=open("fifo1",O_RDONLY);
  read(fd,str,100);
  //printf("%s\n",str);
  close(fd);
  fd3=open(str,O_RDONLY);
  mkfifo("fifo2",0666);
  fd2=open("fifo2",O_WRONLY);
  while(read(fd3,str,100))
  {
        //printf("%s\n",str);
  	write(fd2,str,100);
  }
  close(fd3); 
  close(fd2);
}
