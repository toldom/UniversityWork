//
//  main.c
//  Algorithms and Programming II - Lab 1
//
//  Created by Marcus Toldo on 2017-01-17.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

int power(int, int); //Calculates 'a' to the power 'b'
int factorial(int); //Calculates factorial of 'a'
int summation(int); //Calculates summation of 'a'
int fib(int); //Calculates fibonacci value of 'a'
int gcd(int, int); //Calculates greatest common denominator between 'a' and 'b'

int main(void) {
    //Declaring variables needed for runnign code and storing user inputs
    int userChoice, running = 1, subRunning, a, b, result;
    
    //Opens the main program loop
    while (running) {
        subRunning = 1;
        printf("What function would you like to use?\n");
        printf(" 1. Calculate power (a^b)\n 2. Calculate factorial (a!)\n 3. Calculate summation\n 4. Calculate fibonacci number\n 5. Calculate greatest common denominator (between a, b)\n 0. Close program \n");
        scanf(" %d", &userChoice);
        
        //Opens the switch statement for the user to select a funciton to use
        switch (userChoice) {
            case 0:
                //Terminates the main program
                subRunning = 0;
                running = 0;
            case 1:
                //Opens a secondary program loop
                while(subRunning) {
                    printf("Please enter two numbers (a b): ");
                    scanf("%d %d", &a, &b);
                    
                    //Check if the numbers entered are valid
                    if (a <= 0 || b < 0) {
                        printf("Error: Invalid inputs, inputs must be positive integers\n\n");
                    } else {
                        //Calculates and returns the answer
                        result = power(a, b);
                        printf("The product of %d^%d is %d\n\n", a, b, result);
                        subRunning = 0;
                        //Closes secondary program
                        }
                    }
                break;
            
            case 2:
                while(subRunning) {
                    printf("Please enter a number (a): ");
                    scanf("%d", &a);
                    
                    //Check if the numbers entered are valid
                    if (a < 0) {
                        printf("Error: Invalid inputs, inputs must be integers greater than or equal to zero\n\n");
                    } else {
                        //Calculates and returns the answer
                        result = factorial(a);
                        printf("The factorial of %d is %d\n\n", a, result);
                        subRunning = 0;
                        //Closes secondary program
                    }
                }
                
            case 3:
                while(subRunning) {
                    printf("Please enter a number to calculate the summation of (a): ");
                    scanf("%d", &a);
                    
                    //Check if the numbers entered are valid
                    if (a < 1) {
                        printf("Error: Invalid inputs, inputs must be positive integers\n\n");
                    } else {
                        //Calculates and returns the answer
                        result = summation(a);
                        printf("The summation of %d is %d\n\n", a, result);
                        subRunning = 0;
                        //Closes secondary program
                    }
                }
            
            case 4:
                while(subRunning) {
                    printf("Please enter a number to calculate the fibonacci number of (a): ");
                    scanf("%d", &a);
                    
                    //Check if the numbers entered are valid
                    if (a < 0) {
                        printf("Error: Invalid inputs, inputs must be integers greater than or equal to zero\n\n");
                    } else {
                        //Calculates and returns the answer
                        result = fib(a);
                        printf("The fibonacci number of %d is %d\n\n", a, result);
                        subRunning = 0;
                        //Closes secondary program
                    }

                }
                
            case 5:
                while(subRunning) {
                    printf("Please enter two numbers to calculate the greatest common denominator between them (a b): ");
                    scanf("%d %d", &a, &b);
                    
                    //Check if the numbers entered are valid
                    if (a < 0 || b < 0) {
                        printf("Error: Invalid inputs, inputs must be integers greater than or equal to zero\n\n");
                    } else {
                        //Calculates and returns the answer
                        result = gcd(a, b);
                        printf("The greatest common denominator between %d and %d is %d\n\n", a, b, result);
                        subRunning = 0;
                        //Closes secondary program
                    }
                }
                
            default:
                break;
        }
    }

    return 0;
}

/*
 Objective: Calculates the product of one number put to the power of another
 Input: Two numbers inputted by the user, first number is the base, second number is
 the exponent
 Output: Returns a sentence that formats the two inputted numbers as a math statement
 and states the result to the user
*/

int power(int a, int b) {
    //Declaring the 'product' variable as equal to the 'a' value
    int product = a;
    
    //Opening a for loop that will multiply 'a' by itself 'b' times
    for (int i = b; i > 1; i--) {
        product *= a;
    }
    
    //Returning the result
    return product;
}

//Declaring the factorial function with one perameter, 'a'
int factorial(int a) {
    //Declaring variable 'product' to hold the result calculated
    int product = a;
    //Opening a for loop to increment the number of times equal to the 'a' number
    for(int i = a; i > 1; i--) {
        product *= i-1;
    }
    
    //Returning the result
    return product;
}

/* 
 Objective: Take the inputed number and calculate the summation of
 that number, by adding every number from 1 up to the inputted number
 Input: There in one number inputted by the user that much be greater than zero
 Output: Returns the summation within a sentence, informing the user of the origional
 input number and its summation
*/
int summation(int a) {
    //Declaring variable 'sum' to hold the result calculated
    int sum = a;
    //Calculating the summation and storing it in the 'sum' variable
    for (int i = a; i > 1; i--) {
        sum += i-1;
    }
    
    //Returnign the result
    return sum;
}

/*
 Objective: Take an input and calculate the corresponding number in the
 fibonacci sequence
 Input: One number inputted by the user
 Output: Returns the origional input and the fibonacci number to the user in sentence form
*/
int fib(int a) {
    //Declaring extra variables neede for calculation
    int result = 0, first = 1, second = 1;
    
    //Opens a for loop that will run a-1 times
    for (int i = a-1; i > 1; i--) {
        result = first + second;
        second = first;
        first = result;
    }
    
    //Returns the result
    return result;
}

/*
 Objective: Calculates the greatest common denominator between two numbers
 Input: Two numbers entered by the user
 Output: Returns a sentence that tells the user what the gcd is between the two inputted numbers
*/
int gcd(int a, int b) {
    //Declaring an extra variable
    int tempOne, remainderOne, remainderTwo;
    
    if (b>a) {
        tempOne = b;
        b = a;
        a = tempOne;
    }
    
    tempOne = a;
    remainderOne = a%b;
    
    while (remainderOne > 0) {
        remainderTwo = b % remainderOne;
        b = remainderOne;
        remainderOne = remainderTwo;
    }
    
    
    return b;
    }
