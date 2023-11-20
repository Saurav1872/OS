#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myfunc(void *myvar) {
    char *msg;
    msg = (char*) myvar;
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%s %d\n", msg, i);
        sleep(2);
    }
    return NULL;
}


int main() {
    pthread_t thread1, thread2;
    char *msg1 = "first thread";
    char *msg2 = "second thread";
    int ret1, ret2;
    ret1 = pthread_create(&thread1, NULL, myfunc, (void *)msg1);
    ret2 = pthread_create(&thread2, NULL, myfunc, (void *)msg2);
    printf("Main funciton after pthread_create\n");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("First thread ret1 = %d\n", ret1);
    printf("second thread ret2 = %d\n", ret2);
}