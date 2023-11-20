#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid;
    pid = getpid();
    printf("Current process pid is %d\n", pid);
    printf("forking a child process\n");
    pid = fork();
    if(pid == 0) {
        printf("Child process id: %d and its parent id: %d\n", getpid(), getppid());
    }
    else {
        printf("parent process id %d\n", getpid());
    }
    return 0;
}