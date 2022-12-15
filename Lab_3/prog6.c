#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefds1[2], pipefds2[2];
    int returnStatus1, returnStatus2;
    char pipe1writemessage[20] = "Rain";
    char pipe2writemessage[20] = "Maker";
    char readMessage[20];
    returnStatus1 = pipe(pipefds1);
    returnStatus2 = pipe(pipefds2);
    if (returnStatus1 == -1) {
        printf("Error for pipe 1\n");
        return 0;
    }
    if (returnStatus2 == -1) {
        printf("Error for pipe 2\n");
        return 0;
    }
    int pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error fork\n");
        exit(1);
    }
    else if (pid != 0) { 
        close(pipefds1[0]); close(pipefds2[1]);
        printf("Parent: Writing to pipe 1 - Message is %s\n", pipe1writemessage);
        write(pipefds1[1], pipe1writemessage, sizeof(pipe1writemessage));
        read(pipefds2[0], readMessage, sizeof(readMessage));
        printf("Parent: Reading from pipe 2 - Message is %s\n", readMessage);
    } else {
        close(pipefds1[1]); close(pipefds2[0]);
        read(pipefds1[0], readMessage, sizeof(readMessage));
        printf("Child: Reading from pipe 1 - Message is %s\n", readMessage);
        printf("Child: Writing to pipe 2 - Message is %s\n", pipe2writemessage);
        write(pipefds2[1], pipe2writemessage, sizeof(pipe2writemessage));
    }
    return 0;
}