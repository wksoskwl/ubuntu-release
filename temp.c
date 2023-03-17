#include <stdlib.h>
#include <stdio.h>
  #include <sys/types.h>
  #include <fcntl.h>
  #include <unistd.h>
  #include <string.h>
  #include <errno.h>

int main(){
    int fd = open("temp0.txt", O_RDWR|O_CREAT, 0644);
    char a[1024] = "a1bcabcAZ23";
	write(fd, a, 1024);
	int cnt = 0;
	for(int i = 0;a[i] != '\0';i++){
	if(a[i] >= 'A' && a[i] <= 'Z' || a[i] >= 'a' && a[i] <= 'z')	cnt++;
}
printf("%d\n",cnt);
    close(fd);
}


