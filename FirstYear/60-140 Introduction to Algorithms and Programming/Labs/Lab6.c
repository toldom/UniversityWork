//
//  Lab6.c
//
//  Created by Marcus Toldo on 2016-11-01.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

int main(void) {
    
    //Declaring variables
    int validPin = 39669, running = 1, attemptNumber = 1, userCode;
    
    //Opening the loop
    while (running == 1) {

        //Prompting the user to enter their code, and scannign it in
        printf("Enter pin code (attempt %d): ", attemptNumber);
        scanf("%d", &userCode);
        
        //Checking if user tries to exit logon
        if (userCode == 00000) {
            printf("Shutting down with exit code %d\n\n", userCode);
            running = 0;
        }
        else {
            //Checking if the code is 5 digits in length (between 9999 and 100000)
            if (userCode > 9999 && userCode < 100000) {
                
                //Checking if the digits of the code are divisible by 3
                if (userCode % 3 == 0) {
                    
                    //Checking if the code entered is the valid code
                    if (userCode == validPin) {
                        printf("Code %d is sucsess!\n\n", validPin);
                        running = 0;
                    }
                    
                    //If the code entered is not valid, alert the user, add an attempt
                    else {
                        printf("Code %d is invalid! Not the correct pin\n\n", userCode);
                        attemptNumber ++;
                    }
                }
                
                //If the code is not valid, alert the user, add an attempt
                else {
                    printf("Code %d is invalid! Not divisible by 3\n\n", userCode);
                    attemptNumber++;
                }
            }
            
            //If the code is not valid, alert the user, add an attempt
            else {
                printf("Code %d is invalid! Out of range... \n\n", userCode);
                attemptNumber++;
            }
            
            //If the user had surpassed 6 attempts, lock them out
            if (attemptNumber == 7) {
                printf("Intruder alert!\n\n");
                running = 0;
            }
            
            
        }
    }
        
    return 0;
}
