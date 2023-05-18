#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define SIZE 512

int main(){
	char msg[SIZE];
	int filedes[2];

	pid_t pid;

	if(pipe(filedes) == -1){
		printf("fail");
		exit(0);
	}

	if((pid = fork()) == -1){
		printf("FAIL");
		exit(0);
	}
	else if(pid > 0){
		strcpy(msg,"apple is red\n");
		write(filedes[1],msg,SIZE);
		printf("p : %s\n",msg);
	}
	else if(pid == 0){
		read(filedes[0],msg,SIZE);
		printf("c : %s\n",msg);
	}

}
