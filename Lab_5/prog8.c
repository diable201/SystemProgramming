#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * file;
    char path[255];
    int characters = 0, words = 0, lines = 0;
    printf("Enter source file path: ");
    scanf("%s", path);
    file = fopen(path, "r");
    if (file != NULL) {
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            if (ch == '\n') {
                lines++;
                words++;
            }
            else if (ch ==' ' || ch =='\t') {
                words++;
                characters++;
            }
            else {
                characters++;
            }
        }

        printf("\nTotal characters = %d\n", characters);
        printf("Total words = %d\n", words);
        printf("Total lines = %d\n", lines);
        fclose(file);
        return 0;
    } else {
        printf("\nUnable to open file.\n");
        return 0;
    }
}