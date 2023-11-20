#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, size;
    fd = open("file1", O_RDONLY);
    size = lseek(fd, 0, SEEK_END);

    char buffer;
    lseek(fd, 0, SEEK_SET);
    while(read(fd, &buffer, 1) > 0) {
        write(1, &buffer, 1);
    }
    write(1, "\n", 1);
}