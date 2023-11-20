#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = getpid();
    printf("Current process pid is PID 1: %d\n", pid);
    printf("forking child process\n");
    
    pid = fork();
    if(pid == 0) {
        printf("PID 2: %d\n", getpid());
        pid = fork();
        if(pid == 0) {
            printf("PID 3: %d\n", getpid());
            pid = fork();
            if(pid == 0) {
                sleep(10);
                printf("PID 4: %d (Orphan)\n", getpid());
            }
        }
    }
    else {
        pid = fork();
        if(pid == 0) {
            printf("PID 5: %d\n", getpid());
            pid = fork();
            if(pid == 0) {
                pid = fork();
                if(pid > 0) {
                    sleep(15);
                    printf("PID 6: %d\n", getpid());
                }
                else {
                    printf("PID 7 (Zombie): %d\n", getpid());
                }
            }
        }
    }

    return 0;
}