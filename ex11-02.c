#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 512

int main(){
	char msg[SIZE];
	int filedes[2];
	int i;

	if(pipe(filedes) == -1){
		printf("fail");
		exit(0);
	}
	
	for(i = 0;i<3;i++){
		printf("input\n");
		fgets(msg,SIZE,stdin);
		write(filedes[1],msg,SIZE);
	}

	printf("\n");
	for(i = 0;i<3;i++){
		read(filedes[0],msg,SIZE);
		printf("%s",msg);
	}
}
