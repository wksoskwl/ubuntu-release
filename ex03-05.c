#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int filedes;
	off_t newpos;

	filedes = open(argv[1], O_RDONLY);

	newpos = lseek(filedes, (off_t)0,SEEK_END);

	printf("file size : %ld\n",newpos);
}
