#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

#define SIZE 512

int main(){
	int filedes[2], nread;
	char buffer[SIZE];
	

	pid_t pid;

	if(pipe(filedes) == -1){
		printf("FAIL\n");
		exit(0);
	}

	if((pid = fork()) == -1){
		printf("fork FAIL\n");	
		exit(1);
	}
	else if(pid > 0){
		close(filedes[0]);
		buffer = a;
		write(filedes[1], buffer, SIZE); 
	}
	else{
		close(filedes[1]);
		nread = read(filedes[0], buffer, SIZE);
		printf("%s\n",buffer);
	}
}
