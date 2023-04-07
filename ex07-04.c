#include <unistd.h>
#include <stdio.h>

int main(){
	char* arg[] = {"ls","-l",(char*)0};
	printf("before\n");
	execv("/bin/ls",arg);
	printf("after");
}
