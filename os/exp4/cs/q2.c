#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>


int main() {

    char dname1[] = "my_dir1";
    int a = mkdir(dname1, 0777);

    // if(a == 0 && b == 0) {
    //     printf("* Directories named %s and %s has been created.\n", dname1, dname2);
    // }
    char path[512];
    char filename[] = "my_file1.txt";
    sprintf(path, "%s/%s", dname1, filename);
    int fd1 = open(path, O_CREAT | O_RDONLY | O_WRONLY, 0777);

    printf("Write a line in file1: \n");
    char c;
    do {
        read(0, &c, 1);
        write(fd1, &c, 1);
        
    }
    while(c != '\n');
    printf("%s file has been created.", filename);

    DIR *dp1 = opendir(dname1);
    struct dirent *dptr;
    printf("Contents of %s Directory: \n", dname1);
    while(NULL != (dptr = readdir(dp1))) {
        printf("%s %d %d\n", dptr->d_name, dptr->d_type, dptr->d_reclen);
    }
    printf("-------------------------------\n");


    char dname2[] = "my_dir2";
    int b = mkdir(dname2, 0777);
    char filename2[] = "my_file2.txt";
    sprintf(path, "%s/%s", dname2, filename2);
    int fd2 = open(path, O_CREAT | O_WRONLY, 0777);
    close(fd1);
    sprintf(path, "%s/%s", dname1, filename);
    fd1 = open(path, O_CREAT | O_RDONLY, 0777);

    printf("Copying file from %s/%s to %s/%s .....\n", dname1, filename, dname2, filename2);

    lseek(fd1, 0, SEEK_SET);
    char buffer;
    while(read(fd1, &buffer, 1) > 0) {
        write(fd2, &buffer, 1);
    }
    close(fd1);
    close(fd2);

    DIR *dp2 = opendir(dname2);
    printf("Contents of %s Directory: \n", dname2);
    while(NULL != (dptr = readdir(dp2))) {
        printf("%s %d %d\n", dptr->d_name, dptr->d_type, dptr->d_reclen);
    }
    printf("-------------------------------\n");




}