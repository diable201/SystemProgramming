#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void INThandler(int sig) {
    char c;
    signal(sig, SIG_IGN);
    printf(
        "\nOUCH, it's seems you hit Ctrl-C?\n"
        "Do you really want to quit?\n"
        "Press [y] to confirm or any other key to cancel\n"
    );
    c = getchar();
    if (c == 'y' || c == 'Y') {
        printf("\nOk, bye...\n");
        exit(0);
    }
    else {
        signal(SIGINT, INThandler);
    }
    getchar();
}

int main() {
    signal(SIGINT, INThandler);
    while(1)
        pause();
    return 0;
}
