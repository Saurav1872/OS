#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	
	/*
	int pid = getpid();
	
	printf("Main Function: PID = %d\n", pid);
	
	pid = fork();
	
	if(pid == 0) {
		printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
	}
	else {
		printf("Created a child with PID = %d\n", pid);
		wait(NULL);
	}
	
	int pid = getpid();
	
	printf("Main Function: PID = %d\n", pid);

	int n = 3;
	while(n--) {
		pid = fork();
		
		if(pid == 0) {
			printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());	
		}
		else {
			wait(NULL);
		}
	}
	
	
	
	int pid = getpid();
	
	printf("Main Function: PID = %d\n", pid);
	
	pid = fork();
	
	if(pid == 0) {
		printf("Child Process Sleeps\n");
		sleep(2);
		printf("Child Process Wakes\n");
		printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
	}
	else {
		printf("Created a child with PID = %d\n", pid);
	}
	
	*/
	
	int pid = getpid();
	
	printf("Main Function: PID = %d\n", pid);
	
	pid = fork();
	
	if(pid == 0) {
		printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
	}
	else {
		printf("Parent created a child with PID = %d\n", pid);
		
		char str[50] = "pstree -p ";
		char ppid [7];
		sprintf(ppid,"%d",getpid());
		strcat(str,ppid);
		system(str);
		printf("\n");
		
		printf("Parent Process Sleeps\n");
		sleep(2);
		printf("Parent Process Wakes\n");
		
		// char str2[50] = "ps -o pid --ppid ";
		char str2[50] = "pstree -p ";
		sprintf(ppid,"%d",getpid());
		strcat(str2,ppid);
		system(str2);
		printf("\n");
	}
}
