/*6.WAP to implement Student Database using Linked List with the following structure:
Name
Rollno
Marks of 5 subjects
Average
Result, if the average < 50, then print ‘FAIL’, otherwise ‘PASS’*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int rollno;
    float marks[5];
    float average;
    char result[5];
    struct Student *next;
} Student;

Student *start = NULL;

void insertStudent() {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent->name);
    printf("Enter Roll Number: ");
    scanf("%d", &newStudent->rollno);

    float total = 0;
    printf("Enter marks of 5 subjects: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &newStudent->marks[i]);
        total += newStudent->marks[i];
    }

    newStudent->average = total / 5;
    strcpy(newStudent->result, (newStudent->average < 50) ? "FAIL" : "PASS");

    newStudent->next = NULL;

    if (start == NULL) {
        start = newStudent;
    } else {
        Student *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
}

void displayStudents() {
    Student *temp = start;
    if (temp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Database:\n");
    while (temp != NULL) {
        printf("\nName: %s\nRoll Number: %d\nMarks: ", temp->name, temp->rollno);
        for (int i = 0; i < 5; i++)
            printf("%.2f ", temp->marks[i]);
        printf("\nAverage: %.2f\nResult: %s\n", temp->average, temp->result);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
