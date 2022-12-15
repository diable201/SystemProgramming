#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h>

int main() {
    int qid, len, i; 
    char s[100]; 
    struct {
        long mtype; 
        char mtext[100]; 
    } buff;
    qid = msgget((key_t)10, IPC_CREAT | 0666); 
    if (qid == -1) {
        perror("message queue create failed"); 
        exit(0);
    }
    for (i = 1; i <= 5; i++) { 
        if (msgrcv(qid, &buff, 15, i, 0) == -1) {
            perror("message failed\n"); 
            exit(0);
        }
        printf("Message received from sender is %s\n", buff.mtext);
    }
    printf("All messages are received successfully\n");
}