#include <fcntl.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/stat.h>

int main(int argc, char **argv) {
    int fd1, fd2; 
    int n, count = 0;
    // fd1 = open(argv[1], O_RDONLY); 
    // fd2 = creat(argv[2], S_IWUSR | O_CREAT); 
    rename("file4.txt", "file5.txt");
    // unlink(argv[1]); 
    return (0);
}
