#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int filedes;
	off_t newpos;

	filedes = open(argv[1], O_RDONLY);

	newpos = lseek(filedes, (off_t)3,SEEK_SET);

	printf("file size : %ld\n",newpos);
}
