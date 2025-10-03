#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Task 5: Dynamic Memory for Student Grades
Write a C program that:

Asks the user how many students are in a class.
Dynamically allocates memory to store the grades of each student using malloc().
Lets the user input the grade for each student.
Calculates and prints the highest and lowest grades in the class.
Frees the memory after use.

Output
Enter the number of students: 4
Enter grades: 90 33 100 3
Highest grade: 100
Lowest grade: 3
*/

int main() {
    int studentCount;
    printf("Enter the number of students: ");
    scanf("%d", &studentCount);

    int* studentGrades = (int*)malloc(studentCount * sizeof(int));
    if (studentGrades == NULL) {
        return 1;
    }

    printf("Enter grades: ");
    int highest = - 1;
    int lowest = 100;
    for (int i = 0; i < studentCount; ++i) {
        scanf("%d", &(studentGrades[i]));
        int grade = studentGrades[i];
        if (highest < grade) {
            highest = grade;
        }
        if (lowest > grade) {
            lowest = grade;
        }
    }
    printf("Highest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);
    return 0;
}

