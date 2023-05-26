#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define SIZE 512

int main(){
	char *msg1 = "apple is red";
	char *msg2 = "banana is yellow";
	char buffer[SIZE];
	
	int filedes[2];
	int nread;
	int len1 = strlen(msg1) + 1;
	int len2 = strlen(msg2) + 1;

	if(pipe(filedes) == -1){
		printf("FAIL\n");
		exit(0);
	}

	write(filedes[1],msg1,len1);
	write(filedes[1],msg2,len2);
	
	nread = read(filedes[0],buffer,len1);
	printf("%d ,%s\n",nread,buffer);

	nread = read(filedes[0],buffer,len2);
	printf("%d ,%s\n",nread,buffer);
}
