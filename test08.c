#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int a,b;
	int status;
	scanf("%d %d",&a,&b);
	pid_t pid;
	if((pid = fork()) > 0){
		int mul = 1;
		for(int i = 0;i<b;i++) mul *= a;
		printf("parent : %d\n",mul);
		waitpid(pid, &status, 0);
		printf("finish : %d\n",(status >> 8) + mul);
	}
	else if(pid == 0){
		int sum = 0;
		for(int i = a;i<=b;i++) sum += i;
		printf("child : %d\n",sum);
		exit(sum);
	}
	else{
		printf("fail to fork\n");
	}
}
