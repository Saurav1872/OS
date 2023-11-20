#include <dirent.h>
#include <stdio.h>


/*
    Create Directory:
    int mkdir("pathname/dirname", mode t mode);
    int return = mkdir("directoryname", 0666);


    Opendir system call:
    DIR * opendir("dir name");

    struct dirent *readdir(DIR * dirname);
    rmdir system call
    int rmdir("pathname/dirname");


    Dirent structure:

    struct dirent {
        Ino+t d_ino;    // inode number
        off_t d_off;    // off_set to next dirent
        unsigned short d_reclen; // length of this record
        unsigned char d_type;   // type of file; not supported by all file system types
        char d_name[256];   // filename
    }

*/


/*  
    Program to use directory system call and print the content of the directory:
*/
int main() {
    DIR *dp;
    struct dirent *dptr;
    int b = mkdir("Dir1", 0777);
    dp = opendir("Dir1");
    while(NULL !=(dptr = readdir(dp))) {
        printf("%s ", dptr->d_name);
        printf("%d\n", dptr->d_type);
    }
}