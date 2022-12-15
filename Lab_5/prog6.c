#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *stream;
    int buffer_character;
    stream = fopen("test", "r");
    if (stream == (FILE*)0) {
        fprintf(stderr, "Error opening file(printed to standard error)\n"); 
        fclose(stream);
        exit(1);
    }
    if (fclose(stream) == EOF) {
        fprintf(stderr, "Error closing stream.(printed to standard error)\n"); 
        exit(1);
    }
    return 0;
}