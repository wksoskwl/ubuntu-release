#include<unistd.h>
#include<stdio.h>

int main(int argc, char* argv[]){
	char buffer[1024];
	if(readlink(argv[1],buffer,1024) == -1)
		printf("failed\n");
	else
		printf("good\n");
}
