#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void sigfpeCatcher(int sig) {
    printf("Caught signal %d (%s)\n", sig, strsignal(sig));
    sleep(1);                  
}

int main() {
    printf("Catching SIGFPE\n");

    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigfpeCatcher;
    if (sigaction(SIGFPE, &sa, NULL) == -1)
        printf("sigaction");
    printf("About to generate SIGFPE\n");
    int x, y;
    y = 0;
    x = 1 / y;
    y = x;
    printf("Catched SIGFPE\n");
    exit(0);
}