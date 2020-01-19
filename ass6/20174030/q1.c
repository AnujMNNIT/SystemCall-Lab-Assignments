#include<stdio.h>
#include<sys/types.h>

int main(){

fork(); //creating first child process.
fork(); //creating child process coresponding to first fork.
fork(); //creating child processes corresponding to previous forks.
printf("Hello World\n"); //a process to print "Hello World" in command line console.


return 0;
}
