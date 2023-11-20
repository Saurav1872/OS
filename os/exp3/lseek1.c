#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int n, f;
    char buff[10];
    f = open("demo", O_RDWR);
    read(f, buff, 10);
    write(1, buff, 10);
    lseek(f, 10, SEEK_END); // try executing after commenting this line and observe the code;
    read(f, buff, 10);
    write(1, buff, 10);
    return 0;
}
