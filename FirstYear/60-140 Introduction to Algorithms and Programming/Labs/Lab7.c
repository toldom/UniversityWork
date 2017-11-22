//
//  Lab7.c
//
//  Created by Marcus Toldo on 2016-11-09.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

int main(void) {
    
    //Defining variables
    int numStudents, i = 0, studentNum = 1, gpaCheck, amm1, amm2, amm3, amm4;
    
    //Prompting the user for the number of students, and taking the input
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    //Defining the array to store all student GPAs
    int gpas[numStudents];
    
    //Opening the loop to scan in student GPAs, based on the number of students previously scanned in
    for (studentNum = 1; studentNum <= numStudents; studentNum++) {
        
        //Promting the user to enter each students GPA and storing it in the array
        printf("Enter the GPA of student #%d: ", studentNum);
        scanf("%d", &gpaCheck);
        
        //Checking if the inputted GPA is within the proper range
        if (gpaCheck >= 1 && gpaCheck <= 4) {
            //If it is a proper GPA, it is stored in the array
            gpas[studentNum] = gpaCheck;
        }
        else {
            //If not, resets the loop for this specific student
            printf("Invalid number!\n");
            studentNum--;
        }
        
    }
    
    //Checks each GPA in the array and counts the number of each type of GPA total
    for (i = 0; i <= numStudents; i++) {
        switch (gpas[i]) {
            case 1:
                amm1++;
                break;
            case 2:
                amm2++;
                break;
            case 3:
                amm3++;
                break;
            case 4:
                amm4++;
                break;
        }

    }
    
    //Returns the results to the user
    printf("\n\nThe total number of students is %d \n", numStudents);
    printf("GPA 1 -- %d student(s) \n", amm1);
    printf("GPA 2 -- %d student(s) \n", amm2);
    printf("GPA 3 -- %d student(s) \n", amm3);
    printf("GPA 4 -- %d student(s) \n", amm4);
    
    
    return 0;
}
