#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid;
    pid = getpid();
    printf("current process pid is %d\n", pid);
    printf("forking a child process\n");
    pid = fork();
    if(pid == 0) {
        printf("child process is sleeping\n");
        sleep(10);
        printf("orphan child parent id: %d\n", getpid());
    }
    else {
        printf("parent process completed\n");
    }

    return 0;
}