#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/types.h>
#include <string.h>

/*

    FILE *popen(const char* command, const char *type); // stdio.h



*/

int main() {
    // FILE *rd;
    // char buffer[50];

    // sprintf(buffer, "name here first");

    // rd = popen("wc -w", "w");

    // fwrite(buffer, sizeof(char), strlen(buffer), rd);
    // pclose(rd);

    FILE *rd;
    char buffer[50];


    rd = popen("ls", "r");

    fread(buffer, sizeof(char), 25, rd);
    write(1, buffer, 25);
    pclose(rd);

}