#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int main() {
    int a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int sumOdd = 0, sumEven = 0;
    int pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error fork\n");
        exit(1);
    }
    else if (pid != 0) {
        for (int i = 0; i < 20; i++) {
            if (a[i] % 2 == 0)
                sumEven += a[i];
        }
        printf("I'm the parent process!\n");
        printf("Sum of even numbers is %d\n", sumEven);
    }
    else {
        for (int i = 0; i < 20; i++) {
            if (a[i] % 2 != 0)
                sumOdd += a[i];
        }
        printf("I'm the child process!\n");
        printf("Sum of odd numbers is %d\n", sumOdd);
    }
    return 0;
}