#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid1,pid2;
	char msg = 'h';
	int filedes1[2];
	int filedes2[2];
	char buffer[512] = {0};
	int status;

	if(pipe(filedes1) == -1){
		printf("FAIL\n");
		exit(0);
	}
	if(pipe(filedes2) == -1){
		printf("FAIL2\n");
		exit(0);
	}
	if((pid1 = fork()) == -1){
		printf("fork FAIL\n");
		exit(0);
	}
	else if(pid1 > 0){
		if((pid2 = fork()) == -1){
			printf("fork FAIL2\n");
			exit(0);
		}
		else if(pid2 > 0){
			close(filedes1[0]);
			close(filedes2[0]);
			write(filedes1[1],&msg,1);
			write(filedes2[1],&msg,1);
			printf("send!\n");
			waitpid(pid2,&status,0);
		}
		else{
			close(filedes1[1]);
			close(filedes1[0]);
			close(filedes2[1]);
			read(filedes2[0],buffer,1);
			printf("fork2 : %s\n",buffer);
		}
	}
	else{
		close(filedes1[1]);
		close(filedes2[0]);
		close(filedes2[1]);
		read(filedes1[0],buffer,1);
		printf("fork1 : %s\n",buffer);
	}
}
