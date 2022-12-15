#include <stdio.h>
#include <stdlib.h>
  
int main() {
    FILE *fptr1, *fptr2;
    char source_filename[255];
    char destination_filename[255];
    printf("Enter the filename for copying\n");
    scanf("%s", source_filename);
    printf("Enter the filename for writing\n");
    scanf("%s", destination_filename);
    fptr1 = fopen(source_filename, "r");
    fptr2 = fopen(destination_filename, "w");
    if (fptr1 == NULL || fptr2 == NULL) {
        printf("Error when opening files\n");
        exit(0);
    }
    char c = fgetc(fptr1);
    while (c != EOF) {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    printf("Content successfully copied to %s\n", destination_filename);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}