//
//  A4Q6.c
//
//  Created by Marcus Toldo on 2016-11-18.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    
    //Declaring variables
    int digit;
    long number = 1;
    
    //Opens the while loop
    while (number!=0) {
        
        //Instaciating the boolian array
        bool digit_seen[10] = {false};
        
        //Prompts the user to input a number
        printf("Enter a number: ");
        scanf("%d", &number);
        
        //Code to terminate the program loop
        if (number <= 0)
        {
            printf("Program terminated\n\n");
            break;
        }
        
        //Runs code for is the user enteres a number greater than zero
        while(number>0) {
            
            digit = number % 10;
            if(digit_seen[digit]) break;
            
            else {
                
                digit_seen[digit]= true;
                number/=10;
            }
            
        }
        
        //Prints repeated digit if number is greater than zero
        if(number>0) {
            
            printf("Repeated digit\n\n");
        }
        
        else {
           
            //if number is not repeated, prints
            printf("No repeated digit\n\n");
            number= number+1;
        }
    }
    
    
    return 0;
}
