#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	char *filename = "test.txt";

	if(access(filename, R_OK) == -1 ){
		fprintf(stderr,"User cannot read file %s\n",filename);
		exit(1);
	}
	printf("%s readable procseding\n",filename);

}
