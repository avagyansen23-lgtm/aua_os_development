#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Task 4: Dynamic String Array with realloc
Write a C program that:

Dynamically allocates memory for an array of 3 strings (char pointers) using malloc().
Dynamically allocates memory for each string (each string can have up to 50 characters).
Lets the user input 3 strings.
Prints the strings.
Uses realloc() to allow the user to input 2 more strings (resize the array).
Prints all 5 strings.
Frees all the allocated memory.

Output
Enter 3 strings: My name is

Enter 2 more strings: Senik Avagyan

All 5 strings: My name is Senik Avagyan
*/

int main() {
    const int initial_size = 3;
    const int total_size = 5;
    const int maxLen = 50;

    char** strings = (char **)malloc(initial_size * sizeof(char*));
    if (strings == NULL) {
        return 1;
    }

    printf("Enter 3 strings: ");
    for (int i = 0; i < initial_size; ++i) {
        strings[i] = (char *)malloc((maxLen) * sizeof(char));
        if (strings[i] == NULL) {
            printf("String malloc failed.\n");
            return 1;
        }
        scanf("%s", strings[i]);
    }

    char **temp = realloc(strings, total_size * sizeof(char *));
    if (temp == NULL) {
        printf("Realloc failed.\n");
        for (int i = 0; i < initial_size; ++i) {
            free(strings[i]);
        }
        free(strings);
        return 1;
    }
    strings = temp;

    printf("\nEnter 2 more strings: ");
    for (int i = initial_size; i < total_size; ++i) {
        strings[i] = (char *)malloc((maxLen) * sizeof(char));
        if (strings[i] == NULL) {
            printf("String malloc failed.\n");
            for (int j = 0; j < i; ++j)
                free(strings[j]);
            free(strings);
            return 1;
        }
        scanf("%s", strings[i]);
    }

    printf("\nAll 5 strings: ");
    for (int i = 0; i < total_size; ++i) {
        printf("%s ", strings[i]);
    }
    printf("\n");

    for (int i = 0; i < total_size; ++i) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}

