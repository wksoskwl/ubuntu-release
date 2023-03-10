#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd;
    char pathname[] = "temp.txt";

    if((fd=open(pathname, O_CREAT | O_RDWR, 0644)) == -1)
    {
        printf("ERROR!!!\n");
        exit(1);
    }
    close(fd);
}

