#include <stdio.h>

long int factorial(int num) {
    if (num == 1 || num == 0)
        return 1;
    
    return num * factorial(num - 1);
}

int main() {
    printf("Enter number to find factorial: ");
    int num; scanf("%d", &num);

    if (num < 0) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("\nThe factorial of %d is %ld.\n", num, factorial(num));
    return 0;
}