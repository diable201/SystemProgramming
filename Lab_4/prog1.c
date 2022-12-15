#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h> 
#include <string.h>
#include <fcntl.h>

int main() {
    char src[10], dest[10], buff; 
    int fd, fd1;
    printf("enter the source file name \n"); 
    // scanf("%s\n", src); 
    fd = open("file1.txt", O_RDONLY);
    printf("enter the destination file name\n"); 
    // scanf("%s\n", dest);
    fd1 = open("file2.txt",O_WRONLY|O_CREAT|O_TRUNC|S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH); 
    while (read(fd,&buff,1)) {
        write(fd1,&buff,1);
    }
    printf("The copy of a file is successed\n");
    close(fd);
    close(fd1); 
    return 0;
}
