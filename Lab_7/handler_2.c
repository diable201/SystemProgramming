#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigHandler(int sig) {
    int count = 0;
    if (sig == SIGINT) {
        count++;
        printf("Caught SIGINT (%d)\n", count);
        return;            
    }

    /* Must be SIGQUIT - print a message and terminate the process */
    printf("Caught SIGQUIT - that's all, terminate process\n");
    sleep(1);
    exit(0);
}

int main() {

    if (signal(SIGINT, sigHandler) == SIG_ERR)
        printf("signal");
    if (signal(SIGQUIT, sigHandler) == SIG_ERR)
        printf("signal");

    for (;;)                    
        pause();                
}