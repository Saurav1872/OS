#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


typedef struct {

	float a;
	float b;
	float sum;
} args;

/*
void *func() {
	
	printf("Inside Thread Function\n");
	
	void* ret;
	
	char* str = "Hello from thread";
	
	ret = str;
	pthread_exit(ret);

}


void* func2(void* args) {

	int* a = (int*) args;
	int b = *((int*)args);
	
	printf("a = %d, b = %d\n", *a, b);
	
}

*/

void *add(void* argu) {

	args *arg = (args*) argu;
	arg->sum = arg->a + arg->b;
	
	pthread_exit((void*) arg);
	
}

int main() {

	/*
	pthread_t thread1;
	
	
	pthread_create(&thread1, NULL, func, NULL);
	
	void *a;
	
	pthread_join(thread1, &a);
	
	char* res;
	res = (char*) a;
	
	printf("%s\n", res);
	
	
	
	
	pthread_t thread2;
	
	void* arg;
	int d = 5; 
	
	arg = &d;
	
	pthread_create(&thread2, NULL, func2, arg);
	
	pthread_join(thread2, NULL);
	
	*/
	
	args arg;
	
	arg.a = 5.9f;
	arg.b = 11.19f;
	
	pthread_t thread;
	
	pthread_create(&thread, NULL, add, &arg);
	
	void *res;
	pthread_join(thread, &res);
	
	args resarg = *((args*) res);
	
	printf("Sum = %.2f\n", resarg.sum);
	printf("Sum = %.2f\n", arg.sum);
	
	
	

}
