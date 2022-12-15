#include <stdio.h>
 
int main() {
    FILE *file;
    int numberOfWords = 0;
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File does not exist\n");
        return 0;
    }
    for (char i = getc(file); i != EOF; i = getc(file))
        if (i == '\n' || i == ' ')
            numberOfWords += 1;
    fclose(file);
    printf("The file %s has %d words\n", filename, numberOfWords);
    return 0;
}