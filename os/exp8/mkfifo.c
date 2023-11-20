#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


/*
    // FIFO work in blocked mode by default

    create a named pipe;

    create a sender process (write into pipe)


    create a receiver process (read from pipe)


*/
int main() {

    int res;
    res = mkfifo("fifo1", 0777);
    printf("named pipe created\n");

}