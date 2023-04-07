#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

int fd;

void func(){
	printf("haha\n");
	close(fd);
}

int main(){
	char buffer[1024] = {0};
	fd = open("temp.txt",O_RDONLY);
	while((read(fd, buffer, 1024)) > 0) {
		printf("%s",buffer);
	}
	atexit(func);
	exit(1);
}
