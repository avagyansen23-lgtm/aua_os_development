#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

//Assignment 2

/*
In this assignment, I created two child processes using fork(). 
Each child printed its own PID and exited with a different status code. 
The parent process used waitpid() to wait for the first child and wait() to wait for the second.
After each child terminated, the parent retrieved and printed their exit statuses using WEXITSTATUS().
This assignment helped me understand process creation, synchronization
 and how to handle exit statuses using wait() and waitpid() in C
*/

// output
/*
First child process ID is 106508: exiting with status 2
Second Child process ID is 106509: exiting with status 10
First child exited with exit code:  2
Second child exited with exit code:  10
*/

int main() { 
    pid_t pid = fork();
    int status;
    
    if (pid < 0) {
        perror("fork for first child failed");
        return 1;
    }
    if (pid == 0) {
        printf("First child process ID is %d: exiting with status 2\n", getpid());
        exit(2);
    } 
    pid_t pid2 = fork();
    if (pid < 0) {
        perror("fork for second child failed");
        return 1;
    }
    if (pid2 == 0) {
        printf("Second Child process ID is %d: exiting with status 10\n", getpid());
        exit(10);
    }

    pid_t wPid = waitpid(pid, &status, 0);
    if (wPid == pid) {
        printf("First child exited with exit code:  %d\n", WEXITSTATUS(status));
    }
    wPid = wait(&status);
    if (wPid == pid2) {
        printf("Second child exited with exit code:  %d\n", WEXITSTATUS(status));
    }

    return 0;
} 
