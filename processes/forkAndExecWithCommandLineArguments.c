#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

//Assignment 4

/*
This program demonstrates the use of fork() and execl() to run a command with multiple arguments. It first creates a child process using fork(). 
The child process executes the grep command via execl(), searching for the word "main" inside the file "text.txt". 
This causes the child process to output all lines from the file containing the word "main". Meanwhile, 
the parent process waits for the child process to complete using waitpid() to ensure the grep output is printed first. After the child finishes, 
the parent prints the message "Parent process done". This approach effectively illustrates running an external command with arguments in a child 
process and synchronizing with the parent process for orderly output.
*/


// output
/*
The main road was still empty, dust swirling in the breeze.
He worked in the main building across from the library.
Her main concern was finishing the project on time.
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
        execl("/usr/bin/grep", "grep", "main", "text.txt", NULL);
    } else {
        waitpid(pid, &status, 0);
        std::cout << "Parent process done" << std::endl;
    }
    return 0;
} 
