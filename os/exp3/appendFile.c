#include <stdio.h>
#include <fcntl.h>

int main() {
    int a, b, c, d;
    char buffer[100];
    a = open("new_file2", O_WRONLY|O_APPEND, 0777);
    printf("File descriptor is %d\n");   
}