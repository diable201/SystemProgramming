#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>

int main()
{
    int pid;
    pid=fork(); /* Duplicate */
    if (pid!=0) /* Branch based on return value from fork() */ 
    {
        while (1) sleep(1000); /* never terminate, and never execute a wait() */
    }
    else 
    {
        exit(42); /* Exit with a silly number */
    }
}