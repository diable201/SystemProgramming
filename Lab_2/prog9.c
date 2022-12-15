#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() 
{
    int pid;
    pid = fork(); 
    if (pid < 0) 
    {
        fprintf(stderr, "Error fork\n");
        exit(1);
    }
    if (pid != 0)
    {
        printf("I'm the parent and do some work\n");
        int num, originalNum, remainder, n = 0;
        float result = 0.0;
        printf("Enter an integer: ");
        scanf("%d", &num);
        originalNum = num;
        for (originalNum = num; originalNum != 0; n++) 
        {
            originalNum /= 10;
        }

        for (originalNum = num; originalNum != 0; originalNum /= 10) 
        {
            remainder = originalNum % 10;
            result += pow(remainder, n);
        }

        if ((int)result == num) {
            printf("%d is an Armstrong number\n", num);
        }
        else
        {
            printf("%d is not an Armstrong number\n", num);
        }
        return 0;
    }
}
