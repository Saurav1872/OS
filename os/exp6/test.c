#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_args {
    int *arr;
    int start;
    int mid;
    int end;
};

void* sort(void *args) {
    struct thread_args *ar = (struct thread_args*) args;

    for (int i = ar->start; i < ar->end; i++) {
        for (int j = i; j < ar->end; j++) {
            if (ar->arr[j] > ar->arr[j + 1]) {
                int temp = ar->arr[j];
                ar->arr[j] = ar->arr[j + 1];
                ar->arr[j + 1] = temp;
            }
        }
    }

    for (int i = ar->start; i <= ar->end; i++) {
        printf("%d ", ar->arr[i]);
    }
    printf("\n");

    pthread_exit(NULL);
}

void* merge(void *args) {
    struct thread_args *ar = (struct thread_args*) args;

    int i = ar->start, j = ar->mid + 1, k = 0;
    int size = ar->end - ar->start + 1;
    int *arr = (int*)malloc(size * sizeof(int));

    while (i <= ar->mid && j <= ar->end) {
        if (ar->arr[i] <= ar->arr[j]) {
            arr[k++] = ar->arr[i++];
        } else {
            arr[k++] = ar->arr[j++];
        }
    }

    while (i <= ar->mid) {
        arr[k++] = ar->arr[i++];
    }

    while (j <= ar->end) {
        arr[k++] = ar->arr[j++];
    }

    for (int i = 0; i < size; i++) {
        ar->arr[ar->start + i] = arr[i];
    }

    free(arr);

    pthread_exit(NULL);
}

int main() {
    int arr[] = {1, 6, 2, 9, 3, 8};
    struct thread_args args;
    args.arr = arr;
    args.start = 0;
    args.end = 5;
    args.mid = args.start + (args.end - args.start) / 2;

    for (int i = 0; i < 6; i++) {
        printf("%d ", args.arr[i]);
    }
    printf("\n");

    pthread_t thread1, thread2, thread3;
    struct thread_args arg1, arg2;

    arg1.arr = args.arr;
    arg1.start = args.start;
    arg1.end = args.mid;
    pthread_create(&thread1, NULL, sort, &arg1);

    arg2.start = args.mid + 1;
    arg2.end = args.end;
    arg2.arr = args.arr;
    pthread_create(&thread2, NULL, sort, &arg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_create(&thread3, NULL, merge, &args);
    pthread_join(thread3, NULL);

    for (int i = 0; i < 6; i++) {
        printf("%d ", args.arr[i]);
    }
    printf("\n");

    return 0;
}
