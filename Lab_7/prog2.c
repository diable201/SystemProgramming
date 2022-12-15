#include <sys/types.h> 
#include <stdio.h>
#include <signal.h>

int main() {
    int pid;
    //suspend the process(same as hitting crtl+z) 
    kill(pid, SIGSTOP);
    //continue the process 
    kill(pid, SIGCONT);
}