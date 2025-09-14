#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

//Assignment 2

/*
This program demonstrates creating multiple child processes using fork() and running different commands with execl(). 
The first child executes the ls command to list directory contents, while the second child runs the date command to show the current time. 
The parent process prints "Parent process done" after creating both children. 
To ensure the outputs appear in order, the parent uses sleep() to pause briefly between creating the two children. 
The program effectively shows how to spawn child processes and replace their execution with different commands. 
Using fork() and execl() allows the children to run independently, while the parent continues its work.
*/


// output
/*
fork  fork.c  multipleForkAndExec  multipleForkAndExec.c
Sun Sep 14 16:06:53 UTC 2025
Parent process done
*/

int main() 
{ 
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    if (pid == 0) {
        execl("/usr/bin/ls", "ls", NULL);
    } else {
        sleep(1);
        pid = fork();
        if (pid < 0) {
            perror("second fork failed");
            return 1;
        } 
        if (pid == 0) {
            execl("/usr/bin/date", "date", NULL);
        } else {
            sleep(1);
            std::cout << "Parent process done" << std::endl;
        }
    }
    return 0;
} 
