#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <errno.h>

int main(int argc, char **argv){
    int id, rc;
    id = atoi(argv[1]);
    printf("id = %d\n", id);
    rc = semctl(id, 1, IPC_RMID); 
    if (rc < 0) {
        perror("semctl"); 
        exit(1);
    } else {
        printf("Successfully deleted semaphore with id: %d", id);
    }
    exit(0);
}