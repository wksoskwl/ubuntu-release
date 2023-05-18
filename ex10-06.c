#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<stdio.h>
	
void h(){
	return;
}

int main(){
	pid_t pid;
	
	if((pid = fork()) > 0){
		struct sigaction act;
		act.sa_handler = h;
		sigaction(SIGINT, &act, NULL);
		pause();
		printf("[parent] bye!\n");
	}
	else if(pid == 0){
			printf("[childe] haha\n");
			kill(getppid(), SIGINT);
	}
	else{
		printf("fail\n");
	}
}
