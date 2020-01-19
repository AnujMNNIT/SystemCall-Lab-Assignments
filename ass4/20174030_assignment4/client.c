#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  mkfifo("fifo1",0666);
  //printf("enter the file name");
  char *file="hello";
  //scanf("%s",file);
  int fd=open("fifo1",O_WRONLY);
  write(fd,file,50);
  close(fd);
  int fd2=open("fifo2",O_RDONLY);
  char str[100];
  while(read(fd2,str,100))
  {
     printf("%s",str);
  }
  close(fd2);
 
}
