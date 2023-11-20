#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



void *func(void *args) {
    char *msg;
    msg = (char *) args;
    int i = 0;
    while(msg[i] != '\0') {
        i++;
    }
    // printf("in thread len = %d\n", i);
    int* len = malloc(sizeof(int));
    *len = i;

    pthread_exit(((void*)len));
}

int main() {
    pthread_t thread1;
    char *msg1 = "Hello World!";
    pthread_create(&thread1, NULL, func, (void*)msg1);
    void *a;
    pthread_join(thread1, &a);
    printf("string = %s\n", msg1);
    printf("length of string = %d\n", *(int*)a);
}