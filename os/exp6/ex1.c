#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_STRINGS 3
#define MAX_STRING_LENGTH 100

struct ThreadData {
    const char **strings;
    int numStrings;
};


void *concatenateStrings(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    char *result = malloc(MAX_STRING_LENGTH * MAX_STRINGS);

    if (result == NULL) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }

    result[0] = '\0'; 


    for (int i = 0; i < data->numStrings; ++i) {
        strcat(result, data->strings[i]);
    }

    
    pthread_exit(result);
}

int main() {
    pthread_t concat_thread;
    struct ThreadData threadData;

    // Example strings
    const char *strings[MAX_STRINGS] = {"Hello, ", "world", "!"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);

    threadData.numStrings = numStrings;
    threadData.strings = (const char **)malloc(numStrings * sizeof(const char *));

    
    
    for (int i = 0; i < numStrings; ++i) {
        threadData.strings[i] = strdup(strings[i]);
        
    }

    if (pthread_create(&concat_thread, NULL, concatenateStrings, (void *)&threadData) != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    char *result;
    if (pthread_join(concat_thread, (void **)&result) != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    printf("Concatenated String: %s\n", result);

    free(result);

    for (int i = 0; i < numStrings; ++i) {
        free((char *)threadData.strings[i]);
    }

    free(threadData.strings);

    return 0;
}
