#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum){
	printf("haha\n");
}

int main(){
	struct sigaction act;
	
	sigfillset(&(act.sa_mask));
	act.sa_handler = handler;
	sigaction(SIGINT, &act, NULL);

	printf("pause %d\n",pause());
}
