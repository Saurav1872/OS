#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t a;
    a = fork();
    if(a>0) {
        sleep(20);
        printf("PID of Parent %d\n", getpid());
    }
    else {
        printf("PID of CHILD %d\n", getpid());
    }
}