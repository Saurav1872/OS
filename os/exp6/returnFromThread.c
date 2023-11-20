#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int *a;
struct arg_struct {
    int arg1;
    int arg2;
    int arg3;
};


// void *print_the_arguments(void *arg) {
//     struct arg_struct *ar = (struct arg_struct *) arg;
//     scanf("%d", &ar->arg3);
//     scanf("%d", &ar->arg2);
//     int c = ar->arg2 + ar->arg3;

//     pthread_exit(c);
// }

void *print_the_arguments(void *arg) {
    struct arg_struct *ar = (struct arg_struct *) arg;
    scanf("%d", &ar->arg3);
    scanf("%d", &ar->arg2);
    int *c = malloc(sizeof(int));

    if (c == NULL) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }

    *c = ar->arg2 + ar->arg3;

    pthread_exit(c);
}


int main() {
    pthread_t some_thread;
    struct arg_struct args;
    args.arg2 = 5;
    args.arg3 = 7;

    void *a;
    pthread_create(&some_thread, NULL, print_the_arguments, &args);
    pthread_join(some_thread, &a);
    printf("%d\n", *((int *)a));
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>

// struct arg_struct {
//     int arg1;
//     int arg2;
//     int arg3;
// };

// void *print_the_arguments(void *arg) {
//     struct arg_struct *ar = (struct arg_struct *)arg;

//     // Perform some computation without blocking calls
//     int val = ar->arg2 + ar->arg3;
//     int *c = malloc(sizeof(int)); // Allocate memory on the heap

//     if (c == NULL) {
//         perror("Memory allocation failed");
//         pthread_exit(NULL);
//     }

//     *c = val;
//     pthread_exit((void *)c);
// }

// int main() {
//     pthread_t some_thread;
//     struct arg_struct args;
//     args.arg3 = 5;
//     args.arg2 = 7;

//     void *result;
//     pthread_create(&some_thread, NULL, print_the_arguments, &args);
//     pthread_join(some_thread, &result);

//     if (result != NULL) {
//         printf("%d\n", *((int *)result));

//         // Don't forget to free the allocated memory
//         free(result);
//     } else {
//         fprintf(stderr, "Thread execution failed\n");
//     }

//     return 0;
// }
