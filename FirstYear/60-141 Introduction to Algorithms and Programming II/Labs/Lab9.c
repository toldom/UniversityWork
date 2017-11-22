//
//  main.c
//  Lab9
//
//  Created by Marcus Toldo on 2017-03-29.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int ID;
    char name[40];
    struct student *next;
};
typedef struct student Student;

int getChoice(); //Get the user choice
Student *addToList(Student *SLIST); //Add a student to the list
int printList(Student *SLIST); //Print the list
int printListRR(Student *SLIST); //Recursively print the list in reverse
int searchList(Student *SLIST); //Search the list

int main() {
    
    int userChoice;
    Student *SLIST = NULL;
    
    userChoice = getChoice();
    
    while(userChoice >= 0) {
        
        //Switch statement for different user choices
        switch(userChoice) {
            case 0 :
                exit(0);
                break;
                
            case 1 :
                SLIST = addToList(SLIST);
                break;
            
            case 2 :
                printList(SLIST);
                break;
            
            case 3 :
                printListRR(SLIST);
                break;
                
            case 4 : searchList(SLIST);
                break;
                
            default:
                printf("That is not a valid choice\n");
        }
        
        userChoice = getChoice();
    }
    
    if(SLIST) free(SLIST);
    return 0;
}

/*
    Objective: Get the users choice on which function to run with a menu
    Input: No input
    Output: Returns an int corresponding to user choice
 */
int getChoice() {
    
    int userChoice = 0;
    
    printf("\n1. Add new student to list\n");
    printf("2. Print the student list\n");
    printf("3. Recursively print the student list\n");
    printf("4. Search the list for a student's ID\n");
    printf("0. Quit.\n");
    scanf("%d", &userChoice);
    
    return userChoice;
}

/*
    Objective: Add a student entry to the list
    Input: Recieves a pointer to the student list as input
    Output: Returns the updares srudent list
 */
Student *addToList(Student *SLIST) {
    
    Student *aStudent = (Student *) malloc(sizeof(Student));
    
    printf("Enter student's ID: ");
    scanf("%d", &(aStudent->ID));
    printf("Enter student's name: ");
    scanf(" %[^\n]", aStudent->name);
    
    if (SLIST == NULL) return aStudent;
    
    Student *pStudent = SLIST;
    
    while(pStudent->next != NULL)
        pStudent = pStudent->next;
    
    pStudent->next = aStudent;
    
    return SLIST;
}

/*
    Objective: Print the student list
    Input: Recieve the student list as an input parameter
    Output: Return 0, after having printed the list within the function
 */
int printList(Student *SLIST) {
    
    while(SLIST != NULL) {
        printf("\n%d %s\n\n", SLIST->ID, SLIST->name);
        SLIST = SLIST->next;
    }
    
    return 0;
}

/*
    Objective: Print the student list in reverse order recursivly
    Input: Recieves the student list as input parameter
    Output: Returns 0 after printing the student list
 */
int printListRR(Student *SLIST) {
    
    if(SLIST == NULL) {
        return 0;
    }
    
    printListRR(SLIST->next);
    printf("\n%d %s\n\n", SLIST->ID, SLIST->name);
    
    return 0;
}

/*
    Objective: Search the student list for a student by ID number
    Input: Recieves the student list as an input parameter
    Output: Returns 0 after searching the list and printing the searched for student, if found
 */
int searchList(Student *SLIST) {
    
    int studentID;
    
    printf("Enter student's ID: ");
    scanf("%d", &studentID);
    
    while(SLIST != NULL) {
        if(SLIST->ID == studentID){
            printf("%d %s\n", SLIST->ID, SLIST->name);
            
            return 0;
        }
        
        SLIST = SLIST->next;
    }
    printf("ID %d not found\n\n", studentID);
    
    return 0;
}

