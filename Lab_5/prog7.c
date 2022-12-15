#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h> 

int main() {
    FILE *stream;
    int status; 
    struct stat info;
    stream = fopen("test", "r");
    status = fstat(stream, &info);
    printf("      inode:   %d\n",   (int) info.st_ino);
    printf("     dev id:   %d\n",   (int) info.st_dev);
    printf("       mode:   %08x\n",       info.st_mode);
    printf("      links:   %d\n",         info.st_nlink);
    printf("        uid:   %d\n",   (int) info.st_uid);
    printf("        gid:   %d\n",   (int) info.st_gid);
    printf("last access:   %jd\n",        info.st_atimespec.tv_sec);
    return 0;
}