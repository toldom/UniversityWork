//  a3_epsilon0.c
//  A3Q5
//  Created by Marcus Toldo on 2016-11-02.
//  Copyright © 2016 Marcus Toldo. All rights reserved.

#include <stdio.h>
#include <math.h>

int main(void) {
    
    //Instaciating variables
    float e = 1, fact = 1, term = 0, userInput;
    
    //Prompting the user for input to aproximate the value of e
    printf("Please enter a number to aproximate e to: ");
    scanf("%f", &userInput);
    
    //Calculating the value of e based on the user input
    while (term <= userInput) {
        term ++;
        fact *= term;
        e += 1/fact;
    }
    
    //Returning the result to the user
    printf("The constant e is about: %f \n", e);
    
    return 0;
}
