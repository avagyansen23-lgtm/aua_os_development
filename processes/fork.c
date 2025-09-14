#include <stdio.h>
#include <unistd.h>
#include <iostream>

//Assignment 0


/*
                        parent (Before Line A)
                        /                        \
                       /                          \
                    parent                         child_1      ("After Line A - Before Line B" is printed 2 times, child1 process is created after first fork())
                      /   \                         /   \
                     /     \                       /     \ 
                 parent     child_2             child_1   child_1_1  (After Line B - Before Line C" is printed 4 times) parent and child1 create child processes
                /  \          /  \               /  \          \           \
               /    \        /    \             /    \          \           \
         parent   child4  child2  child_2_1  child1  child_1_2  child_1_1   child_1_1_1  ("After Line C") is printed 8 times

         Each fork() doubles existing processes
*/

int main() 
{ 
    std::cout << "Before Line A" << std::endl;                                         
    fork();                      // Line A                                            
    std::cout << "After Line A - Before Line B" << std::endl;                               

    fork();                      // Line B
    std::cout << "After Line B - Before Line C" << std::endl;

    fork();                      // Line C
    std::cout << "After Line C" << std::endl;

} 
