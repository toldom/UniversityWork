//
//  a2_addfrac.c
//
//  Created by Marcus Toldo on 2016-10-21.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

int main(void) {
    //Instaciating integer variables for the numerators and denominators of two fractions
    int num1, denom1, num2, denom2, result_num, result_denom, placeholder;
    char opperation = '+';
    
    //Prompting the user to enter both fractions to be calculated
    printf("Enter the two fractions seperated by the opperation you would like to perform: ");
    scanf("%d/%d %c %d/%d", &num1, &denom1, &opperation, &num2, &denom2);
    
    //Checking what opperation the user inputted and performing the appropriate computation
    if (opperation == '+') {
        //Calculating the result of the addition
        if (denom1 == denom2) {
            result_num = num1 + num2;
            result_denom = denom1;
        } else {
            result_num = num1*denom2 + num2*denom1;
            result_denom = denom1 * denom2;
        }
        
        //Printing the result of the addition to the user
        printf("The sum is %d/%d\n", result_num, result_denom);
    } else if (opperation == '-') {
        if (denom1 == denom2) {
            result_num = num1 - num2;
            result_denom = denom1;
        } else {
            //Calculating the result of the subtraction
            result_num = num1*denom2 - num2*denom1;
            result_denom = denom1 * denom2;
        }
        
        //Printing the result of the subtraction to the user
        printf("The difference is %d/%d\n", result_num, result_denom);
    } else if (opperation == '*') {
        //Calculating the result of the multiplication
        result_num = num1 * num2;
        result_denom = denom1 * denom2;
        
        //Printing the result of the multiplication to the user
        printf("The product is %d/%d\n", result_num, result_denom);

    } else if (opperation == '/') {
        //Calculating the result of the division
        placeholder = denom2, denom2 = num2, num2 = placeholder;
        result_num = num1 * num2;
        result_denom = denom1 * denom2;
        
        //Printing the result of the division to the user
        printf("The quotient is %d/%d\n", result_num, result_denom);
    }

    return 0;
}
