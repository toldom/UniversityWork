//
//  main.c
//  Assignment 6
//
//  Created by Marcus Toldo on 2017-04-03.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/*
 Data structure to store student information
 Includes an int for the studentID
 float array of size 10 to hold 10 marks
 and a float for GPA
 */
struct studentInfo {
    int studentID;
    
    float gradesAray[10];
    float GPA;
};
typedef struct studentInfo StudentInfo;

//Function to recieve a students 10 grades and calculate the GPA
float calculateGPA(float gradesArray[10]);

int saveStudentInfo(StudentInfo studentInfo);

int loadStudentInfo(StudentInfo studentArray[10]);

int main(void) {
    
    StudentInfo studentArray[10];
    
    loadStudentInfo(studentArray);
    
    
    return 0;
}

/*
    Objective: Quickly calculate the GPA of a student based on 10 marks
    Input: Recieves a float array of size 10 to calculate the average of
    Output: Returns a float value corresponding to the average of the grades
 */
float calculateGPA(float gradesArray[10]) {
    
    float sum = 0, average;
    
    for (int i = 0; i < 10; i++) {
        sum += gradesArray[i];
    }
    
    average = sum/10;
    
    return average;
}

//Empty function
int saveStudentInfo(StudentInfo studentInfo) {
    
    FILE *outputfp = fopen("assign6out.dat", "w");
    
    char outputLineBuffer[256];
    
    
    
    return 0;
}

/*
    Objective: Read in student info from an input text file, store it in the structure list, and calculate the GPA's
    Input: Receievs the structure array as an input parameter
    Output: Returns 0, but manipulates the structure array within the function
 */
int loadStudentInfo(StudentInfo studentArray[10]) {
    
    FILE *fp = fopen("assign6.txt", "r");
    
    char buffer[256];
    
    //i = current position in the structure list
    for(int i = 0; i < 10; i++) {
        fscanf(fp, " %[^\n]\n", buffer);
        
        char *token = strtok(buffer, " ");
        studentArray[i].studentID = atoi(token);
        
        //j = current position in the grades array at the current point in the structure list
        for (int j = 0; j < 10; j++) {
            token = strtok(NULL, " ");
            studentArray[i].gradesAray[j] = atof(token);
        }
        
        studentArray[i].GPA = calculateGPA(studentArray[i].gradesAray);
        
    }
    
    fclose(fp);
    
    return 0;
}
