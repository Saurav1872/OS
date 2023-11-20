#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = getpid();
    printf("Current process pid is %d\n", pid);
    printf("forking child process\n");
    
    pid = fork();
    if(pid > 0) {
        pid = fork();
        printf("PID: %d\n", getpid());
    
    }
    else {
        printf("PID: %d\n", getpid());
    }

    return 0;
}