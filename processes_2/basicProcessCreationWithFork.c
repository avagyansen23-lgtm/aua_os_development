#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

//Assignment 1

/*
Printed parent and child processess' IDs using getPid() function
Parent process ID is printed without waiting for child ones.
*/


// output
/*
Parent process ID is 96870
Child process ID is 96871
*/

int main() { 
    pid_t pid = fork();
    int status;
    
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    if (pid == 0) {
        pid_t pid = getpid(); // Get child process ID
        printf("Child process ID is %d\n", pid);
        return 0;
    } else {
        pid_t pid = getpid(); // Get Parent process ID
        printf("Parent process ID is %d\n", pid);
    }
    return 0;
} 
