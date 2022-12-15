#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() {
    int pfds[2];
    char buf[30]; 
    if (pipe(pfds) == -1) {
        perror("Pipe is not created");
        exit(1); 
    } 
    if (!fork()) {
        printf("CHILD: Writing to the pipe\n"); 
        write(pfds[1],"Hello World, I am child", 23); 
        printf("CHILD:Exiting\n");
        exit(0); 
    }
    else {
        printf("PARENT:reading from the pipe\n");
        read(pfds[0], buf, 23);
        printf("PARENT:Received Data is :%s", buf); 
    }
}