#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	int NUM = 10;
	pid_t pid[NUM];
	int status[NUM];
	for(int i = 0;i<NUM;i++){
		pid[i] = -1;
	}
	pid[0] = fork();
	for(int n = 1;n<NUM;n++){
		if(pid[n-1] > 0){
			pid[n] = fork();
		}
	}
	int cnt = 0;
	for(int n = 0;n<NUM;n++){
		if(pid[n] > 0)	cnt++;
	}

	if(cnt == NUM){
		for(int n = 0;n<NUM;n++){
			waitpid(pid[n],&status[n],0);
		}
		printf("I'm parent\n");
	}
	else{
		printf("I'm child\n");
	}

}
