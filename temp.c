#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void readFile(){
	int fd = open("temp.txt", O_RDWR | O_CREAT, 0664);
	char a[1024] = "yoochanhong";
	write(fd, a, 12);
	close(fd);
}

int calculator(){
	int count = 0;
	int fd = open("temp.txt", O_RDWR | O_CREAT, 0664);
	char b[1024] = {};
	read(fd, b, 12);
	for (int i = 0; i < strlen(b); i++){
		if((b[i] >= 65 && b[i] <= 90) || (b[i] >= 97 && b[i] <= 122)) count++;
	}
	close(fd);
	printf("%s(%d)\n", strerror(errno), errno);
	return count;
}


int main()
{
	readFile();
	int c = calculator();
	printf("%d\n", c);
}
