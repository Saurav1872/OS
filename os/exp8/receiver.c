#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


/*
    // FIFO work in blocked mode by default

    create a named pipe;

    create a sender process (write into pipe)


    create a receiver process (read from pipe)


*/
int main() {

    // Sender Program

    int res, n;
    char buffer[100];
    // res = open("fifo1", O_NONBLOCK, O_RDONLY);
    res = open("fifo1", O_RDONLY);

    read(res, buffer, 100);
    printf("Data Receiver by receiver %d is: %s\n", getpid(), buffer);

}