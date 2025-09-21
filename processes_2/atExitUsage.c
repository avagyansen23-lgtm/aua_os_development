#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Assignment 3

/*
In this assignment, I registered two functions using atexit() that print messages when the program exits.
 After calling exit(1), I observed that the functions were executed in reverse order of registration, 
 showing that atexit() follows a LIFO order. This is useful for cleanup tasks like closing files or 
 freeing memory during normal program termination.
*/


// output
/*
Main function is running.
Exiting the program...
Cleanup Function 2: Called at program exit.
Cleanup Function 1: Called at program exit.
*/

void cleanup1() {
    printf("Cleanup Function 1: Called at program exit.\n");
}

void cleanup2() {
    printf("Cleanup Function 2: Called at program exit.\n");
}

int main() {
    atexit(cleanup1);
    atexit(cleanup2);

    printf("Main function is running.\n");
    printf("Exiting the program...\n"); 

    exit(0);
}