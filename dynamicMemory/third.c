#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Task 3: Resizing an Array Using realloc with Memory Shrinking
Write a C program that:

Dynamically allocates memory for an array of 10 integers using malloc().
Lets the user input 10 values.
Resizes the array using realloc() to only hold 5 integers (shrink the memory).
Prints the first 5 values of the resized array.
Frees the memory after use.

Output
Enter 10 integers: 1 3 4 2222 3 5 66 7 8 10
 1  3  4  2222  3  5  66  7  8  10 
Array after resizing  1  3  4  2222  3 
*/

int main() {
    int sum = 0;

    int* arr = (int*) malloc(10 * sizeof(int));
    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
        printf(" %d ", arr[i]);
    }
    arr = realloc(arr, 5);
    if (arr == NULL) {
        free (arr);
        return 1;
    }
    printf("\nArray after resizing ");

    for (int i = 0; i < 5; ++i) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
