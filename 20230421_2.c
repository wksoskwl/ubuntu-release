#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    pid_t pid;
    int i, status;
    for (i = 1; i < argc; i++)
    {
        pid = fork();
        if (pid == 0) 
        {
            char* wc_argv[] = {"wc",argv[i],NULL};
            execvp("wc", wc_argv);
            exit(1);
        }
        else if (pid > 0) 
        {
            waitpid(pid, &status, 0);
        }
    }
}

