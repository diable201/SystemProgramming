#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
  
int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, (void*)0, 0);

    printf("Write data in shared memory: ");
    scanf("%[^\n]s", str);
    printf("Data successfully written: %s\n",str);
      
    shmdt(str);
    return 0;
}