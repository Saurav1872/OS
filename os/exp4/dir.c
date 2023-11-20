#include <sys/stat.h>
#include <stdio.h>
// #include <unistd.h>
#include <dirent.h>

int main() {
    DIR *dp;
    struct dirent *direntPt;
    dp = opendir("HELLO");
    if(dp == NULL) {
        printf("error\n");
    }

    while((direntPt=readdir(dp))!= NULL) {
        printf("%s \n", direntPt->d_name);
        printf("%ld \n", direntPt->d_ino);
    }

    closedir(dp);
}