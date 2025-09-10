#include <iostream>

void assignment1() {
    std:: cout << "\n______First Assignment_____" << std::endl;
    int number = 4;
    int * numPtr = &number;
    std::cout << "Printing the address of the integer using the variable " << &number << std::endl;
    std::cout << "Printing the address of the integer using the pointer " << numPtr << std::endl;
    *numPtr = 6;
    std::cout << "Printing the value of the integer after modification " << number << std::endl;

}

void assignment2() {
    std:: cout << "\n______Second Assignment_____" << std::endl;

    int numberArray[5] = {10, 20, 30, 40, 50};
    int* ptr = numberArray;

    for (int i = 0; i < 5; ++i) {
        std::cout << *(ptr + i) << std::endl;
    }
    *(numberArray + 0) = 1;
    *(numberArray + 1) = 2;
    *(numberArray + 2) = 3;
    *(numberArray + 3) = 4;
    *(numberArray + 4) = 5;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Printing using ptr -> " << *(ptr+i) << std::endl;
        std::cout << "Printing using array name -> " << numberArray[i] << std::endl;
    }
}

void swap(int* a, int* b) {
    std:: cout << "\n______Third Assignment_____" << std::endl;

    std::cout << "Before swap" << std::endl;
    std::cout << "First Number is " << *a << std::endl;
    std::cout << "Second Number is " << *b << std::endl;

    int temp = *a;
    *a = *b;
    *b = temp;
    
    std::cout << "After swap" << std::endl;
    std::cout << "First Number is " << *a << std::endl;
    std::cout << "Second Number is " << *b << std::endl;
}

void assignment4() {
    std:: cout << "\n______Forth Assignment_____" << std::endl;

    int number = 4;
    int* ptr = &number;
    int** doublePtr = &ptr;
    
    std::cout << "Printing using ptr -> " << *(ptr) << std::endl;
    std::cout << "Printing using double ptr -> " << *(*(doublePtr)) << std::endl;
}


void assignment5() {
    std:: cout << "\n______Fifth Assignment_____" << std::endl;

    char str[] = "Hello";
    int size = 0;
    for (char* ptr = str; *ptr != '\0'; ++ptr) {
        std::cout<< *ptr;
        ++size;
    }
    std::cout << "\nThe size of the string is " << size;
    std::cout << std::endl;
}

int main()
{
    assignment1();

    assignment2();

    int number1 = 2;
    int number2 = 6;
    swap(&number1, &number2);

    assignment4();
    
    assignment5();

    return 0;
}


