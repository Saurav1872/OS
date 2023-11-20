#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// pthread_mutex_t lock;

sem_t sem;


int shared = 0;

void *func() {

	int local;
	
	// pthread_mutex_lock(&lock);
	sem_wait(&sem);
	// critical section
	local = shared;		
	printf("Shared read in func as value: %d\n", local);
	local++;
	sleep(1);
	shared = local;
	// critical section done
	
	// pthread_mutex_unlock(&lock);
	sem_post(&sem);
	printf("Shared in func write as value: %d\n", local);
}


void *func2() {

	int local;
	
	// pthread_mutex_lock(&lock);
	sem_wait(&sem);
	// critical section
	local = shared;		
	printf("Shared read in func2 as value: %d\n", local);
	local--;
	sleep(1);
	shared = local;
	// critical section done
	
	// pthread_mutex_unlock(&lock);
	sem_post(&sem);
	printf("Shared in func2 write as value: %d\n", local);
	
}


int main() {

	sem_init(&sem, 0, 1);

	shared = 10;

	pthread_t thread1, thread2;
	
	pthread_create(&thread1, NULL, func, NULL);
	pthread_create(&thread2, NULL, func2, NULL);
	
	
	printf("Shared variable value: %d\n", shared);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("Shared variable value: %d\n", shared);

}
