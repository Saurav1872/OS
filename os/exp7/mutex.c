#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int shared = 5;
pthread_mutex_t l;

void* func1() {
    int local;
    pthread_mutex_lock(&l);

    printf("thread 1 reads shared as: %d\n", shared);
    local = shared;
    local = local + 1;
    sleep(2);
    shared = local;
    pthread_mutex_unlock(&l);
    printf("thread 1 writes shared as: %d\n", shared);
    pthread_exit(NULL);
}
void* func2() {
    int local;
    pthread_mutex_lock(&l);

    printf("thread 2 reads shared as: %d\n", shared);
    local = shared;
    local = local - 1;
    sleep(2);
    shared = local;
    pthread_mutex_unlock(&l);
    printf("thread 2 writes shared as: %d\n", shared);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func1, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

}