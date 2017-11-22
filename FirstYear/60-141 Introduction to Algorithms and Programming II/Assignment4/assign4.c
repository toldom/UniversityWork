//
//  main.c
//  Assignment 4
//
//  Created by Marcus Toldo on 2017-03-19.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct CourseInfo {
    int courseID;
    char courseName[50];
    char courseCode[12];
    char term[6];
};

typedef struct CourseInfo courseInfo;

int loadCourseInfo(courseInfo courseData[20]);
int displayCourseInfo(courseInfo courseData[20], int);
int addCourseInfo(courseInfo courseData[20], int);
int searchCourseInfo(courseInfo courseData[20], int);


int main(void) {
    typedef struct CourseInfo courseInfo;
    
    struct CourseInfo courseData[20];
    
    //Getting ammount of initial data
    int arraySize;
    /*printf("Enter a number: ");
    scanf("%d", &arraySize);*/
    arraySize = 5;

    //Setting initial courseIDs
    for (int i = 1; i < arraySize; i++) {
        int courseNumber = i+1;
        
        courseData[i].courseID = courseNumber;
    }
    
    //Setting 0th course ID to 1
    courseData[0].courseID = 1;

    printf("Reading in bulk course info from input file\n");
    
    //Getting initial course input data
    loadCourseInfo(courseData);
    
    printf("Displaying course info");
    
    //Printing course data
    displayCourseInfo(courseData, arraySize);
    
    //Adding course data
    arraySize = addCourseInfo(courseData, arraySize);
    
    //Displaying the course info again, with the new data
    displayCourseInfo(courseData, arraySize);
    
    
    //Searching for a specific course
    searchCourseInfo(courseData, arraySize);
    
    
    return 0;
}

/*
 Objective: Get a bulk ammount of course data at once, and store it in the structure
 Input: Recieves the structure and current place in the sttucture to store data as input parameters
 Output: Returns 0 but performs opperations on the structure data within the function
 */
int loadCourseInfo(courseInfo courseData[20]) {
    
    char buffer[256] = {'\0'};
    
    //Opening the input file to read from
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    
    for (int k = 0; k < 5; k++) {
        
        fscanf(inputFile, " %[^\n]\n", buffer);
        
        char * token = strtok(buffer, ","), tokenBuffer[256];
        
        //Code to capitalize the whole course name string
        tokenBuffer[0] = toupper(token[0]);
        
        for (long i = strlen(token); i > 0; i--) {
            tokenBuffer[i] = toupper(token[i]);
        }
        
        
        //Taking the rest of the input and sorting it into the structure
        strcpy(courseData[k].courseName, tokenBuffer);
        
        token = strtok(NULL, ",");
        strcpy(courseData[k].courseCode, token);
        
        token = strtok(NULL, ",");
        strcat(courseData[k].courseCode, token);
        strcat(courseData[k].courseCode, "-");
        
        token = strtok(NULL, ",");
        strcat(courseData[k].courseCode, token);
        strcat(courseData[k].courseCode, "-");
        
        token = strtok(NULL, ",");
        strcat(courseData[k].courseCode, token);
        
        token = strtok(NULL, ",");
        strcpy(courseData[k].term, token);
        
        token = strtok(NULL, ",");
        strcat(courseData[k].term, token);
        
    }
    
    fclose(inputFile);
    
    return 0;
}

/*
    Objective: Pring out all the info stored in the CourseInfo structure
    Input: Recieves the courseData structure, and the size of the structure
    Output: Returns 0, but prints the structure data within the function
 */
int displayCourseInfo(courseInfo courseData[20], int arraySize) {
    
    //Formatted print statement for column headdings
    printf("\n\n%-*s %-*s %-*s %-*s\n",6, "ID", 50, "Name", 13, "Code", 9, "Term");

    //Formatted print statement for each set of data in the structure
    for (int i = 0; i < arraySize; i++) {
        printf("%-*d %-*s %-*s %-*s\n",6, courseData[i].courseID, 50, courseData[i].courseName, 13, courseData[i].courseCode, 5, courseData[i].term);
    }
    
    printf("\n");
    
    return 0;
}

/*
    Objective: Add a new entry manually into the courseData structure
    Input: Recieves the structure and current array size as input parameters
    Output: Returns an int value for the new lenght of the structure, and manipulates the structure data within the fucntion
 */
int addCourseInfo(courseInfo courseData[20], int lastCourseID) {
    
    int nextCourseID = lastCourseID+1, isUnique = 0;
    
    char buffer[256] = {'\0'};
    char buffer2[256] = {'\0'};
    char courseCodeCheck[12] = {'\0'};
    printf("Please input course data of the form CourseName,Faculty,Subject,Level,Section,Semester,Year\n");
    scanf("%s", buffer);
    
    //Creating a second copy of the buffer
    stpcpy(buffer2, buffer);
    
    //Creating a second token to be used on the second buffer
    char *token2 = strtok(buffer2, ",");
    token2 = strtok(NULL, ",");
    
    //Putting the course code of the new data into a check string
    strcpy(courseCodeCheck, token2);
    
    token2 = strtok(NULL, ",");
    strcat(courseCodeCheck, token2);
    strcat(courseCodeCheck, "-");
    
    token2 = strtok(NULL, ",");
    strcat(courseCodeCheck, token2);
    strcat(courseCodeCheck, "-");
    
    token2 = strtok(NULL, ",");
    strcat(courseCodeCheck, token2);
    
    
    //Comparing the new course code with all existing course codes, to see if it is the same or not
    for (int i = 0; i < lastCourseID; i++) {
        if (strcmp(courseData[i].courseCode, courseCodeCheck) == 0) {
            isUnique = 0;
        } else {
            isUnique = 1;
        }
    }
    
    //If the course code is different than any other course, adds the new course data to the strcuture
    //If it is the same, just returns the previous structure position, effectively nothing happens
    if (isUnique) {
        char * token = strtok(buffer, ","), tokenBuffer[256];
        
        courseData[lastCourseID].courseID = nextCourseID;
        
        
        tokenBuffer[0] = toupper(token[0]);
        
        for (long i = strlen(token); i > 0; i--) {
            tokenBuffer[i] = toupper(token[i]);
        }
        
        strcpy(courseData[lastCourseID].courseName, tokenBuffer);
        
        token = strtok(NULL, ",");
        strcpy(courseData[lastCourseID].courseCode, token);
        
        token = strtok(NULL, ",");
        strcat(courseData[lastCourseID].courseCode, token);
        strcat(courseData[lastCourseID].courseCode, "-");
        
        token = strtok(NULL, ",");
        strcat(courseData[lastCourseID].courseCode, token);
        strcat(courseData[lastCourseID].courseCode, "-");
        
        token = strtok(NULL, ",");
        strcat(courseData[lastCourseID].courseCode, token);
        
        token = strtok(NULL, ",");
        strcpy(courseData[lastCourseID].term, token);
        
        token = strtok(NULL, ",");
        strcat(courseData[lastCourseID].term, token);
        
        return nextCourseID;
    } else {
        return lastCourseID;
    }
    
}

/*
    Objective: Search the course info structure for a given ID or name, print that info if found
    Input: Receievs the structure and size of the structure as input
    Output: Returns 0, but prints the data found (or error message) within the function
 */
int searchCourseInfo(courseInfo courseData[20], int arraySize) {
    
    char searchTerm[50] = {'\0'};
    int isInt = 0, foundPosition = -1, idSearch = -1;
    
    printf("Enter a course name or courseID to search for: ");
    scanf("%s", searchTerm);
    
    //If conditional for every number from 0-9, to check if the user is searchung for a integer, and therefoe a course ID as opposed to a name
    if (searchTerm[0] == '0' || searchTerm[0] == '1' || searchTerm[0] == '2' || searchTerm[0] == '3' || searchTerm[0] == '4' || searchTerm[0] == '5' || searchTerm[0] == '6' || searchTerm[0] == '7' || searchTerm[0] == '8' || searchTerm[0] == '9') {
        idSearch = atoi(searchTerm);
        isInt = 1;
    }
    
    //Case for if the user is searching for a course ID
    if (isInt) {
        for (int i = 0; i < arraySize; i++) {
            if (courseData[i].courseID == idSearch) {
                foundPosition = i;
            }
        }
    
    //Case for if the user inputted a string, and is searching for a course by name
    } else {
        
        char searchTermBuffer[50] = {'\0'};
        strcpy(searchTermBuffer, searchTerm);
        
        searchTermBuffer[0] = toupper(searchTermBuffer[0]);
        
        for (long i = strlen(searchTermBuffer); i > 0; i--) {
            searchTermBuffer[i] = toupper(searchTermBuffer[i]);
        }
        
        for (int i = 0; i < arraySize; i++) {
            if (strcmp(searchTermBuffer, courseData[i].courseName) == 0) {
                foundPosition = i;
            }
        }
    }
    
    //Formatted print statement for if the course the user was searching for is found
    if (foundPosition > -1) {
        printf("\n%-*s %-*s %-*s %-*s\n",6, "ID", 50, "Name", 13, "Code", 9, "Term");
        
        printf("%-*d %-*s %-*s %-*s\n",6, courseData[foundPosition].courseID, 50, courseData[foundPosition].courseName, 13, courseData[foundPosition].courseCode, 5, courseData[foundPosition].term);
    } else {
        //Print statement for if the course was not found
        printf("That course does not exist\n\n");
    }
    
    return 0;
}
