#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h> 
#include <unistd.h>
#define BUFSIZE 1

int main (int argc, char **argv) {
    int fd1; int n; char buf;
    fd1 = open(argv[1], O_RDONLY); 
    printf("Displaying content of file\n"); 
    while((n = read(fd1, &buf, 1)) > 0) {
        printf("%c",buf); /* or
        write(1,&buf,1); */ 
    }
    return (0); 
}
