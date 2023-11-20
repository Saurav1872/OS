#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[10];
    read(0, buffer, 10);
    write(1, buffer, 10);
}