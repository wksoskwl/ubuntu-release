#include <unistd.h>
#include <stdlib.h>

int main(){
	setenv("MYDATA", "5", 0);	
	
	execl("20230421_3_2","20230421_3_2",(char*)0);
}
