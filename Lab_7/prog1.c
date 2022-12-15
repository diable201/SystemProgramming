#include <stdio.h> 
#include <stdlib.h> 
#include <mach/error.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/sem.h>

int main(void) {
    key_t key;
    int semid;
    union semun arg;
    if ((key = ftok("demo.c", "j")) == -1) {
        perror("ftok");
        exit(1);
    }
    if ((semid = semget(key, 1, 0666 | IPC_CREAT)) == -1) {
        perror("semget");
        exit(1);
    }
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("smctl");
        exit(1);
    }
    return 0;
}