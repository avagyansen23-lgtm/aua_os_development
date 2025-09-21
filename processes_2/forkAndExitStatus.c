#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
//Assignment 4

/*
In this assignment, I created two child processes using fork(). Each child printed its PID and exited with a 
different status code—5 and 10. The parent process used waitpid() to wait for each child individually. 
After each child exited, the parent checked whether the child exited normally using WIFEXITED() and printed the 
corresponding exit status using WEXITSTATUS(). This demonstrated how to manage multiple processes and retrieve 
their exit statuses in a controlled and reliable way.
*/


// output
/*
Child 1: PID = 104350, exiting with status 5
Child 2: PID = 104351, exiting with status 10
Parent: Child 1 (PID = 104350) exited normally with status 5
Parent: Child 2 (PID = 104351) exited normally with status 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;
    int status;

    child1 = fork();
    if (child1 < 0) {
        perror("fork failed for child1");
        exit(1);
    } else if (child1 == 0) {
        printf("Child 1: PID = %d, exiting with status 5\n", getpid());
        exit(5);
    }

    child2 = fork();
    if (child2 < 0) {
        perror("fork failed for child2");
        exit(1);
    } else if (child2 == 0) {
        printf("Child 2: PID = %d, exiting with status 10\n", getpid());
        exit(10);
    }

    pid_t wpid;

    wpid = waitpid(child1, &status, 0);
    if (wpid == child1) {
        if (WIFEXITED(status)) {
            printf("Parent: Child 1 (PID = %d) exited normally with status %d\n", child1, WEXITSTATUS(status));
        } else {
            printf("Parent: Child 1 (PID = %d) exited abnormally.\n", child1);
        }
    }

    wpid = waitpid(child2, &status, 0);
    if (wpid == child2) {
        if (WIFEXITED(status)) {
            printf("Parent: Child 2 (PID = %d) exited normally with status %d\n", child2, WEXITSTATUS(status));
        } else {
            printf("Parent: Child 2 (PID = %d) exited abnormally.\n", child2);
        }
    }

    return 0;
}