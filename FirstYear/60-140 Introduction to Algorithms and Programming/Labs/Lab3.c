//
//  main.c
//  Lab3
//
//  Created by Marcus Toldo on 2016-10-05.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

int main(void) {
    //Part B
    //Declaring 10 variables for each digit of the ISBN number
    int isbnZero;
    int isbnOne;
    int isbnTwo;
    int isbnThree;
    int isbnFour;
    int isbnFive;
    int isbnSix;
    int isbnSeven;
    int isbnEight;
    int isbnCheck;
    
    //Primpting the user for input of the first 9 digits to calculate the check digit
    printf("Enter the IDSB-10 Number of form (1 2 3 4 5 6 7 8 9) here: ");
    //Scanning in the 9 inputs
    scanf("%d %d %d %d %d %d %d %d %d %d \n", &isbnZero, &isbnOne, &isbnTwo, &isbnThree, &isbnFour, &isbnFive, &isbnSix, &isbnSeven, &isbnEight, &isbnCheck);
    
    //Calculating the sum of products of each digit
    int sumOfProducts =  isbnZero * 10 + isbnOne * 9 + isbnTwo * 8 + isbnThree * 7 + isbnFour * 6 + isbnFive * 5 + isbnSix * 4 + isbnSeven * 3 + isbnEight * 2;
    
    //Finding the remainder when divided by 11
    int remainder = sumOfProducts % 11;
    
    //Storing the final value as the check digit
    isbnCheck = 11 - remainder;
    
    //Returning the information to the user
    printf("The check digit of this ISBN-10 number is %d \n", isbnCheck);
    
}
