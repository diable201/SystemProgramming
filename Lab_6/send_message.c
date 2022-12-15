#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

int main() {
    int qid, len, i; 
    char s[100];
    struct {
        long mtype; 
        char mtext[100]; 
    } message, buff;
    qid = msgget((key_t)10, IPC_CREAT | 0666); 
    if (qid == -1) {
        perror("message queue create failed"); 
        exit(1);
    } 
    for (i = 1; i <= 5; i++) {
        printf("Enter the message to send\n"); 
        scanf("%s", s); 
        strcpy(message.mtext, s); 
        message.mtype = i; 
        len = strlen(message.mtext); 
        printf("The message sended is: %s\n", s);
        if (msgsnd(qid, &message, len + 1, 0) == -1) {
            perror("message failed\n"); 
            exit(1);
        }
    }
    printf("All messages are sended successfully");
}