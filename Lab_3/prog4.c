#include <sys/types.h>
#include <stdio.h> 
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *p;
    int_fast32_t count = 0;
    dir = opendir(".");
    if (dir == NULL) {
        printf("Directory opening problem\n");
        return 0; 
    }
    while ((p = readdir(dir)) != NULL) {  
        char *name = p->d_name;
        if (p->d_type == DT_DIR) {
            if (!strcmp(name, ".") || !strcmp(name, ".."))
                continue;
            count++;
        }
    }
    printf("In current directory there is: %u subdirectories.\n", count);
    closedir (dir); 
    return 0;
}
