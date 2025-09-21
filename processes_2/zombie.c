#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
//Assignment 5

/*
I initially created a child process without using wait(), and added a sleep() in the parent to observe the 
zombie state using htop. After the child exited, it became a zombie, which I confirmed with ps and htop—the 
child appeared with a Z state. I then updated the program to use waitpid() in the parent to retrieve the child’s 
exit status, which successfully prevented the zombie process. The wait() and waitpid() 
functions allow the parent to clean up the child’s process entry after termination, avoiding zombies.
*/


// output
/*
Child 1: PID = 100832, exiting with status 5
Child exited with exit code:  5
Parent is exiting 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1;
    int status;

    child1 = fork();
    if (child1 < 0) {
        perror("fork failed for child1");
        exit(1);
    } else if (child1 == 0) {
        printf("Child 1: PID = %d, exiting with status 5\n", getpid());
        exit(5);
    } else {
        pid_t pid = waitpid(child1, &status, 0);
        if (pid == child1) {
            printf("Child exited with exit code:  %d\n", WEXITSTATUS(status));
        }
        printf("Parent is exiting \n");
    }

    return 0;
}