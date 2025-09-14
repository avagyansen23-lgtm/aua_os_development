#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

//Assignment 3

/*
This program creates a child process using fork(). Inside the child process, execl() is used to run the echo command with the argument "Hello from child process". 
This replaces the child’s process image with the echo program, which prints the message to the standard output. 
The parent process waits for the child to complete using waitpid() to ensure the child’s message is printed first. 
After the child finishes, the parent prints "Parent process done". This approach demonstrates how to pass arguments to a program run by execl() 
and how the parent can synchronize its output with the child.
*/


// output
/*
Hello from child process
Parent process done
*/

int main() 
{ 
    pid_t pid = fork();
    int status;
    
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    if (pid == 0) {
        execl("/usr/bin/echo", "echo", "Hello from child process", NULL);
    } else {
        waitpid(pid, &status, 0);
        std::cout << "Parent process done" << std::endl;
    }
    return 0;
} 
