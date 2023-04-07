#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid;
	int n;
	scanf("%d",&n);
	pid = fork();
	if(pid > 0)	{
		int sum = 0;
		for(int i = 1;i<=n;i++)	sum += i;
		printf("sum(bumo) : %d\n",sum);
	}
	else if(pid == 0){
		int mul = 1;
		for(int i = 1;i<=n;i++) mul *= i;
		printf("mul(jasik) : %d\n",mul);
	}
}
