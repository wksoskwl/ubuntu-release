#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(){
	pid_t pid;

	if((pid = fork())>0){
		sleep(1);
		exit(1);
	}
	else if(pid == 0){
		int fd = open("time.txt",O_RDWR | O_CREAT, 0644);
		setsid();
		time_t result = time(NULL);
		char buffer[1024] = {0};
		for(int i = 0;i<60;i++){
			strcpy(buffer, asctime(localtime(&result)));
			write(fd, buffer, strlen(buffer));
			sleep(10);
		}
	}
}
