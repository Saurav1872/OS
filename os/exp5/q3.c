#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = getpid();
    printf("Current process pid is PID 1: %d\n", pid);
    printf("forking child process\n");
    
    pid = fork();   // p2
    if(pid > 0) { // p1
        pid = fork(); // p4
        if(pid == 0) {  // p4
            pid = fork();  //p5
            if(pid > 0) {  // p4
                sleep(5);
                printf("PID 5: %d (Zombie)\n", getpid());
            }
            else {      // p5
                sleep(10);
                printf("PID 4: %d (Orphan)\n", getpid());
            }
        }
    
    }
    else {
        pid = fork();
        if(pid > 0) {
            printf("PID 3: %d\n", getpid());
        }
        else {
            printf("PID 2: %d\n", getpid());

        }
    }

    return 0;
}