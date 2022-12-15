#include <stdio.h> 
#include <unistd.h> 
#include <sys/ipc.h>

int main() {
    int fd[2]; int n = 0, i; 
    pipe(fd);
    if (fork() == 0) {
        /* create Child process */ 
        close(1); dup(fd[1]); close(fd[0]); /* try not read from the pipe in this example. So close fd[0]. */ 
        for (i = 0; i < 10; i++) {
            printf("%d\n",n);
            n++; 
        }
    } else { /* Parent process */
        close(0); dup(fd[0]);
        /* Now that stdout has been redirected, printf automatically writes into the pipe. */ 
        /* Redirect the stdin of this process to the pipe*/
        close(fd[1]);
        /* will not write into the pipe.So we close fd[1]. */
        for (i = 0; i < 10; i++) {
            scanf("%d", &n);
            /* Now that stdin has been redirected, scanf automatically reads from the pipe. */
            printf("n = %d\n", n);
            /* try stdout of this has not changed . So this will be shown in the terminal.*/ 
            sleep(1);
        }
    }
}