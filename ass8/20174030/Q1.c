//specify the action to be associated
//with the SIGCHLD signal using sigaction() function

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int status=0;

void SIGCHLDhandler(int _signal) {
	signal(SIGCHLD, SIG_IGN);
	printf("SIGCHLD caught\n");
	printf("exit status = %d\n", status);
	while(1);
	signal(SIGCHLD, SIGCHLDhandler);
}

int main() {
	int pid = fork();
	if(!pid) {
		printf("terminating child process...\n");
		exit(0);
	} else {
		sigset_t mymask;
		sigemptyset(&mymask);
		//sigaddset(&mymask,SIGINT);
		struct sigaction sigAction;
		sigAction.sa_flags = 0;
		sigAction.sa_handler = SIGCHLDhandler;
		sigAction.sa_mask=mymask;
		sigaction(SIGCHLD, &sigAction, NULL);  
		signal(SIGCHLD,SIGCHLDhandler);
		wait(&status);
	}
	return 0;
}
