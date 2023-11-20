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
    // res = open("fifo1", O_NONBLOCK, O_WRONLY);
    res = open("fifo1", O_WRONLY);
    printf("named pipe created\n");

    write(res, "Message", 7);
    printf("Sender Process having PID %d send the data\n", getpid());

}