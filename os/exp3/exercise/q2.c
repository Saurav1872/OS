#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[1];
    int fd;
    fd = open("file4", O_CREAT | O_RDWR);
    do {
        read(0, buffer, 1);
        if(buffer[0] != '$') {
            write(fd, buffer, 1);
        }
    }
    while(buffer[0] != '$');
    write(1, "\n", 1);

    close(fd);
}