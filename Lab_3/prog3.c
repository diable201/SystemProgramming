#include<stdio.h> 
#include<unistd.h> 
#include<sys/stat.h> 
#include<fcntl.h> 
#include<stdlib.h> 
#include<dirent.h> 

int main(int argc,char *argv[]) {
    struct dirent *p; 
    DIR *dp; 
    struct stat b; 
    dp = opendir("."); 
    if (dp == NULL) {
        printf("\nDirectory opening problem\n");
        return 0; 
    }
    while ((p=readdir(dp)) != NULL) {
        if (stat(p->d_name,&b) < 0) {
            printf("\nStat failure \n");
            exit(0); 
        }
    switch (b.st_mode & S_IFMT ) {
        case S_IFREG: 
            printf(" - "); break;
        case S_IFDIR: 
            printf(" d"); break; 
        case S_IFCHR: 
            printf(" c"); break; 
        case S_IFBLK: 
            printf(" b"); break; 
        case S_IFLNK: 
            printf(" l"); break;
        case S_IFSOCK: 
            printf(" s"); break;
        case S_IFIFO: 
            printf(" p"); break;
    }
    if (S_IRUSR & b.st_mode) 
        printf(" r");
    else
        printf(" -"); 
    if (S_IWUSR & b.st_mode) 
        printf(" w");
    else
        printf(" -"); 
    if (S_IXUSR & b.st_mode)
        printf(" x"); 
    else
        printf(" -"); 
    if (S_IRGRP & b.st_mode)
        printf(" r"); 
    else
        printf(" -"); 
    if (S_IWGRP & b.st_mode)
        printf(" w"); 
    else
        printf(" -"); 
    if (S_IXGRP & b.st_mode)
        printf(" x"); 
    else
        printf(" -"); 
    if (S_IROTH & b.st_mode)
        printf(" r");
    else printf(" -");
    if (S_IWOTH & b.st_mode) 
        printf(" w");
    else
        printf(" -"); 
    if(S_IXOTH & b.st_mode)
        printf(" x"); 
    else
        printf(" -"); 
    printf("%3d ",b.st_nlink); 
    printf("%4d ",b.st_uid); 
    printf("%4d ",b.st_gid); 
    printf("%6lld ",b.st_size); 
    printf("%9ld",b.st_ctime);
    printf(" %s\n",p->d_name); 
    }
}
