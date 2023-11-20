#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    
    int fd, size;
    fd = open("file1", O_RDONLY);
    size = lseek(fd, 0, SEEK_END);
    int half = size/2;
    int fd2, fd3;
    char buffer[size+1];
    fd2 = open("file2", O_CREAT | O_RDWR);
    fd3 = open("file3", O_CREAT | O_RDWR);

    // first half
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, half);
    write(fd2, buffer, half);

    // second half
    lseek(fd, half, SEEK_SET);
    read(fd, buffer, half);
    write(fd3, buffer, half);

    close(fd);
    close(fd2);
    close(fd3);

    return 0;
}
