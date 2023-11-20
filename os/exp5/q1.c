#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = getpid();
    printf("Current process pid is %d\n", pid);
    printf("forking n child process\n");
    for (int i = 0; i < 3; i++)
    {

        pid = fork();
        if (pid == 0)
        {
            printf("Child process id: %d and its parent id: %d\n", getpid(), getppid());
        }
    }
    return 0;
}