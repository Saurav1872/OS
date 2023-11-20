#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 1

// Structure to hold parameters for the thread
struct ThreadData {
    int input;
    int result;
};

// Thread function that performs some computation
void *threadFunction(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    
    // Perform some computation
    data->result = data->input * 2;

    // Exit the thread and return the result
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct ThreadData threadData[NUM_THREADS];

    // Set the input values for the threads
    threadData[0].input = 5;

    // Create the thread and pass the corresponding data
    if (pthread_create(&threads[0], NULL, threadFunction, (void *)&threadData[0]) != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    // Wait for the thread to finish
    if (pthread_join(threads[0], NULL) != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    // Access the result from the thread
    printf("Result from thread: %d\n", threadData[0].result);

    return 0;
}
