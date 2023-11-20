#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* max(void* args) {
    int* nums;
    nums = (int*) args;
    int max  = nums[0];
    for (int i = 0; i < 5; i++)
    {
        // printf("%d ", nums[i]);
        if(nums[i] > max) {
            max = nums[i];
        }
    }
    // printf("\n");

    // printf("%d\n", max);

    int* result = malloc(sizeof(int));
    *result = max;
    pthread_exit(((void*) result));
    
}

void* min(void* args) {
    int* nums;
    nums = (int*) args;
    int min  = nums[0];
    for (int i = 1; i < 5; i++)
    {
        if(nums[i] < min) {
            min = nums[i];
        }
    }
    // printf("%d\n", min);
    int* result = malloc(sizeof(int));
    *result = min;
    pthread_exit(((void*) result));
    
}

void* average(void* args) {
    int* nums;
    nums = (int*) args;
    int size = sizeof(args) / sizeof(int);
    int sum  = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += nums[i];
    }
    float average = ((float)sum) / 5;
    float* result = malloc(sizeof(float));
    *result = average;
    pthread_exit(((void*) result));
    
}


int main() {
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    int nums[5] = {1, 5, 2, 9, 7};
    pthread_create(&thread1, NULL, max, &nums);
    pthread_create(&thread2, NULL, min, &nums);
    pthread_create(&thread3, NULL, average, &nums);
    void *max;
    void *min;
    void *avg;
    pthread_join(thread1, &max);
    pthread_join(thread2, &min);
    pthread_join(thread3, &avg);
    printf("Max = %d\n", *((int*)max));
    printf("Min = %d\n", *((int*)min));
    printf("Average = %.2f\n", *((float*)avg));

}