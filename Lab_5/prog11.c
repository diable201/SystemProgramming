#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    void *shared_memory;
    char buff[255];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);
    shared_memory = shmat(shmid, NULL, 0);
    printf("Key of shared memory is %d\n", shmid);
    printf("Process attached at %p\n",shared_memory);
    printf("Enter some data to write to shared memory\n");
    read(0, buff, 100);
    strcpy(shared_memory, buff);
    printf("Your data is: %s\n",(char *)shared_memory);
    return 0;
}