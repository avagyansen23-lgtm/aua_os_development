#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

//Assignment 1




// output
/*
fork    forkAndExecWithArgs    forkAndExecWithCommandLineArguments    multipleForkAndExec    report.txt         simpleForkAndExec.c
fork.c  forkAndExecWithArgs.c  forkAndExecWithCommandLineArguments.c  multipleForkAndExec.c  simpleForkAndExec  text.txt
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
        std::cout << "Parent process done" << std::endl;
    }
    return 0;
} 
