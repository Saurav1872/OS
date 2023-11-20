#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    printf("Main Process\n");


    execlp("ls", "ls", "-l", (char*)NULL);

    printf("Hello World!");

    perror("execlp");

    return 1;
}