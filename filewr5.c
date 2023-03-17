#include <unistd.h>
#include <fcntl.h>

int main(){
	int fdin, fdout;
	char buffer[1024];	
	ssize_t nread;

	fdin = open("temp1.txt", O_RDONLY);
	fdout = open("temp2.txt",O_WRLONY | O_CREAT | O_TRUNC, 0644);

	while(nread = read(fdout, buffer, nread) > 0){
		if(write(fdout, buffer, nread) < nread){
			close(fdin);
			close(fdout);
		}
	}
	close(fdin);
	close(fdout);
}

