#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
  
int main() {
    FILE *fptr1, *fptr2;
    char source_filename[255];
    char destination_filename[255];
    printf("Enter the filename for moving\n");
    scanf("%s", source_filename);
    printf("Enter the new filename\n");
    scanf("%s", destination_filename);
    fptr1 = fopen(source_filename, "r");
    fptr2 = fopen(destination_filename, "w");
    if (fptr1 == NULL) {
        printf("Error when opening file %s\n", source_filename);
        exit(0);
    }
    char c = fgetc(fptr1);
    while (c != EOF) {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    printf("Content successfully moved to %s\n", destination_filename);
    fclose(fptr1);
    fclose(fptr2);
    remove(source_filename);
    return 0;
}