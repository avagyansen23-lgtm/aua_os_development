#include <stdio.h>
#include <stdlib.h>

/*
Task 1: Dynamic Integer Array with Sum Calculation
Write a C program that:

Asks the user for a number n.
Dynamically allocates memory for an array of n integers using malloc().
Lets the user input n integers.
Calculates and prints the sum of the integers.
Frees the memory after use.

Output
Enter the number of elements: 4
Enter 4 integers: 33 44 55 66 
Sum of the array: 198
*/


int main() {
    int n = 0;
    int sum = 0;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int* arr = (int*) malloc(5 * sizeof(int));
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            free (arr);
            return 1;
        }
        sum += arr[i];
    }
    printf("Sum of the array: %d\n", sum);
    free(arr);

    return 0;
}

