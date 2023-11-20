#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>


struct my_msg {
    long int msg_type;
    char some_text[BUFSIZ];
};

int main() {
    int running = 1;

    int msgid;

    struct my_msg some_data;
    long int msg_to_rec = 0;
    msgid = msgget((key_t)3333, 0666 | IPC_CREAT);
    if(msgid == -1) {
        printf("Error in creating queue\n");
    }

    while(running) {
        msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_rec, 0);
        printf("Data Received: %s\n", some_data.some_text);
        if(strncmp(some_data.some_text, "end", 3) == 0) {
            running = 0;
        }
    }
    msgctl(msgid, IPC_RMID, 0);
}