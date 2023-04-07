#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int status;

	pid = fork();

	if(pid > 0){
		printf("waiting\n");
		wait(&status);
		printf("%d\n",status);
	}
	else if(pid == 0){
		sleep(1);
		printf("haha\n");
		exit(256);
	}
	else{
		printf("error\n");
	}
}
