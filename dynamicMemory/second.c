#include <stdio.h>
#include <stdlib.h>

/*
Task 2: Using calloc for Initialized Array with Average Calculation
Write a C program that:

Asks the user for a number n.
Dynamically allocates memory for an array of n integers using calloc() (so the array is zero-initialized).
Lets the user input n integers.
Calculates the average of the array.
Prints the initial values (all zeroes) and the updated array.
Frees the memory after use.

Output
Enter the number of integers: 3
Initial array arguments: 0  0  0 
Enter 3 numbers of integers: 33 22 55
The average is 36
*/

int main() {
    int n = 0;
    int sum = 0;

    printf("Enter the number of integers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    int* arr = (int*) calloc(n, sizeof(int));
    printf("Initial array arguments:");
    for (int i = 0 ; i < n; ++i) {
        printf(" %d ", arr[i]);
    }
    printf("\nEnter %d numbers of integers: ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            free (arr);
            return 1;
        }
        sum += arr[i];
    }
    printf("The average is %d \n", sum / n);
    free(arr);
}