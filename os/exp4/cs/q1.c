/*
    Write a program using directory system calls make a directory on desktop and create a file inside the directory and list the contents of the directory
*/

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    char dir[] = "My_dir";
    int a = mkdir(dir, 0777);
    if(a != -1) {
        printf("Your directory has been created\n");
    }

    char path[512];
    char fname[] = "my_file";
    sprintf(path, "%s/%s", dir, fname);

    int fd1 = open(path, O_CREAT | O_RDWR);
    if(fd1 != -1) {
        printf("%s has been created.\n", fname);
    }

    DIR *dp = opendir(dir);
    struct dirent *dptr;
    while(NULL != (dptr = readdir(dp))) {
        printf("%s %d\n", dptr->d_name, dptr->d_type);
    }

}