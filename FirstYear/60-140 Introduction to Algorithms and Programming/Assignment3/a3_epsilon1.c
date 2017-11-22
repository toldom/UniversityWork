//  a3_epsilon1.c
//  A3Q6
//  Created by Marcus Toldo on 2016-11-04.
//  Copyright © 2016 Marcus Toldo. All rights reserved.

#include <stdio.h>

int main(void) {
    
    //Instaciating variables
    float i = 1, epsilon, term= 1.0, e = 0.0, fact = 1;
    
    //Prompting the user for input
    printf("Enter a small float value for epilison: ");
    scanf("%f", &epsilon);
    
    //Loop to perform the epsilon calculation
    while(term >= epsilon){
        e = e + term;
        fact = fact * i;
        i = i+ 1;
        term = 1 / fact;
    }
    
    //Printing the result to the user
    printf("Approximation of eps: %f \n", e);
    
    return 0;
}
