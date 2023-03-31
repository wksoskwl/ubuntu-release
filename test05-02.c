#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int cntFile = 0;
	int cntDir = 0;
	DIR* dirp;
	struct dirent *dentry;

	if((dirp = opendir(".")) == NULL){
		exit(1);
	}

	while(dentry = readdir(dirp)){
		if(dentry->d_ino != 0){
			{
				if(opendir(dentry->d_name) == NULL)	cntFile++;
				else    cntDir++;
			}		
		}
	}
	printf("file : %d, dir : %d\n",cntFile, cntDir);

	closedir(dirp);
}
