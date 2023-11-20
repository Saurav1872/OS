#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd1, fd2, n;
    char buff[20];
    fd1=open("po.txt", O_RDONLY);
    printf("fd1 is %d\n", fd1);
    n = read(fd1, buff, 15);
    printf("n for po.txt is %d\n", n);
    fd2 = open("qw", O_WRONLY);
    printf("fd2 is %d\n", fd2);
    write(fd2, buff, n);
    return 0;
}
