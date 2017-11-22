//
//  main.c
//  Assignment 5
//
//  Created by Marcus Toldo on 2017-03-29.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct CourseInfo {
    int courseID;
    char courseName[30];
};
typedef struct CourseInfo courseInfo;

struct StudentInfo {
    char studentID[9];
    char firstName[20];
    char lastName[25];
    
    int numberOfCourses;
    courseInfo ArrayOfCourses[10];
};
typedef struct StudentInfo studentInfo;

struct Node {
    studentInfo data;
    struct Node *next;
};
typedef struct Node node;

node *head = NULL;

int addStudent();

int searchStudentID(char studentID[9], int);

int deleteStudent(char studentID[9]);

bool exitFunc();

int main(void) {
    
    int userChoice;
    bool running = true;
    
    node *temp = (node*) malloc(sizeof(node));
    
    
    studentInfo *studentDir = (studentInfo *) malloc(sizeof(studentInfo));
    
    while (running) {
        printf("What would you like to do?\n1: Add new student\n2: Delete a student\n3: Search for a student\n4: Display current students\n5: Save student information to file\n6: Exit\n");
        scanf("%d", &userChoice);
    
        if (userChoice == 1) {
            addStudent();
        } else if (userChoice == 2) {
            deleteStudent("11111111");
        } else if (userChoice == 3) {
            char searchID[9];
            printf("Enter an ID to search for: ");
            scanf("%s", searchID);
            
            searchStudentID(searchID, 0);
        } else if (userChoice == 4) {
            //Print students
        } else if (userChoice == 5) {
            //Save info
        } else if (userChoice == 6) {
            running = exitFunc();
        } else {
            printf("\n%d is not a valid input\n", userChoice);
        }
        
    }
    
    
    
    
    
    return 0;
}

/*
 Objective: Add a student to the list
 Input: None
 Output: Returns 0, manipulating the list within the function
 */
int addStudent() {
    
    node *temp = (node*) malloc(sizeof(node));
    
    char checkID[9];
    char newFirstName[20];
    char newLastName[25];
    
    char newCourseName[6];
    
    printf("Please enter a student ID for the new student: ");
    scanf("%s", checkID);
    
    strcpy(temp ->data.studentID, checkID);
    
    int sameCheck = searchStudentID(checkID, 1);
    
    if (sameCheck == 0) {
        
        strcpy(temp->data.studentID, checkID);


        printf("\nEnter the first name of the student: ");
        scanf("%s", newFirstName);
        char letter = newFirstName[0];
        newLastName[0] = toupper(letter);
        
        strcpy(temp ->data.firstName, newFirstName);
        
        printf("Enter the last name of the student: ");
        scanf("%s", newLastName);
        letter = newLastName[0];
        newLastName[0] = toupper(letter);
        strcpy(temp ->data.lastName, newLastName);
        
        printf("Enter the number of courses this student will be attending: ");
        scanf("%d", &temp ->data.numberOfCourses);
        
        for (int i = 0; i < temp ->data.numberOfCourses; i++) {
            printf("Enter the course ID for course %d: ", i+1);
            scanf("%d",&temp ->data.ArrayOfCourses[i].courseID);
            
            printf("Enter the name for course %d: ", i+1);
            scanf("%s", newCourseName);
            strcpy(temp ->data.ArrayOfCourses[i].courseName, newCourseName);
            printf("\n");
        }
        
    } else {
        printf("That student ID is already taken\n");
    }
    
    head = temp;
    
    
    return 0;
}

/*
 Objective: Search for a student and either just return if their ID is found, or print their info
 Input: Recieves a student ID as input, and either 1 or 0 for if it is to print info when found or not
 Output: Returns 0 if the ID is not found, 1 if the ID is found
 */
int searchStudentID(char studentID[9], int check) {
    
    node *temp = (node*) malloc(sizeof(node));
    temp = head;
    
    if (check == 1) {
        if (temp == NULL) {
            return 0;
        }
        
        
        while (temp -> next != NULL) {
            int equalCheck = strcmp(studentID, temp -> data.studentID);
            
            if (equalCheck == 0) {
                
                return 1;
            } else {
                temp = temp -> next;
            }
        }
    } else if (check == 0) {
        while (temp->next != NULL) {
            
            int equalCheck = strcmp(studentID, temp -> data.studentID);
            
            if (equalCheck == 0) {
                printf("Student found!\n%s\n%s\n%s\n%d\n", temp ->data.studentID, temp ->data.firstName, temp -> data.lastName, temp ->data.numberOfCourses);
                for (int i = 0; i < temp ->data.numberOfCourses; i++) {
                    printf("%s%d", temp->data.ArrayOfCourses[i].courseName, temp->data.ArrayOfCourses[i].courseID);
                }
                
                //return 0;
            } else {
                temp = temp -> next;
            }
        }
    }
    
    
    
    return 0;
}

/*
 Objective: Delete a student from the list
 Input: Recieves a student ID as input
 Output: Returns 0 after freeing the memory
 */
int deleteSltudent(char studentID[9]) {
    
    node *temp = (node*) malloc(sizeof(node));
    temp = head;
    
    if (temp == NULL) {
        printf("That student ID was not found!\n");
        return 0;
    }
    
    while (temp -> next != NULL) {
        int check = strcmp(temp ->data.studentID, studentID);
        
        if (check == 0) {
            free(temp);
            return 0;
        } else {
            temp = temp ->next;
        }
    }
    
    printf("That ID was not found!\n");
    
    
    return 0;
}

/*
 Objective: Close all allocated memory blocks and quit the main loop
 Input: None
 Output: Return false to set the loop running to false, to end execution of the program
 */
bool exitFunc() {
    node *temp = (node*) malloc(sizeof(node));
    temp = head;
    
    if (temp == NULL) {
        return false;
    }
    
    while (temp -> next != NULL) {
        free(temp);
    }
    
    return false;
}
