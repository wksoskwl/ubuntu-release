#include <sys/types.h> 
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) 
{ 
	DIR *dirp; 
	if((dirp = opendir(argv[1])) == NULL) 
	{ 
		fprintf(stderr, "Error:not dir\n"); 
		exit(1); 
	} 
	else{
		printf("good\n");
	}

	/* 디렉터리 목록을 읽어오는 부분 */ 

	closedir(dirp); 
} 
