#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


int main() 
{
    int pid;
    pid = fork();
    if (pid < 0) 
    {
        fprintf(stderr, "Error fork\n");
        exit(1);
    }

    if (pid == 0) 
    {
        char str[] = "fear of the dark";

        int i = 0;
        char c;
   
        while (str[i]) 
        {
            c = str[i];
            str[i] = (toupper(c));
            i++;
        }

        printf("Uppercase string : %s\n", str);
    }
    return 0;
}