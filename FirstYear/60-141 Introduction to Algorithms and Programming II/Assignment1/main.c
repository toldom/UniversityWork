//
//  main.c
//  Assignment 1
//
//  Created by Marcus Toldo - 104623006 on 2017-01-19.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int find_prime_count(int, int); //Function that will cound the number of times a given prime number occurs in N!
int find_next_prime(int); //Finds the next prime number
int is_prime(int); //Funciton to determien if a number is prime or not
int calculateArraySize(int); //Function to determine the number of spaces needed in our output array


int main(void) {
    
    //Declaring variables to be used in main function
    bool running, mainRunning = true, greenLight = false;
    int userInput;
    
    //Opening the text input file and pulling the numve
    FILE *input = fopen("input.txt", "r");
    while(!feof(input) || mainRunning) {
        
        
        //Assigns current input line to variable
        fscanf(input, "%d", &userInput);
        
        //Checks current input
        //if 0 is detected, closes program
        if (userInput == 0) {
            return 0;
        //If input it out of range, prints an error and skips calculating that factorial
        } else if (userInput < 2 || userInput > 100) {
            printf("Invalid input, 2 <= N <= 100\n\n");
            
        //If input is OK, gives go ahead to calculate factorial
        } else {
            greenLight = true;
        }
        
        if (greenLight) {
            //Sets the array size based on the largest needed prime factor of the facorial number
            int arraySize = calculateArraySize(userInput);
            int productArray[arraySize][2];
            
            //Calculates all the factorial numbers and stores them in a 2D array
            running = true;
            int currentPrime = 2;
            for (int i = 0; i < arraySize; i++) {
                productArray[i][0] = currentPrime;
                productArray[i][1] = find_prime_count(userInput, currentPrime);
                currentPrime = find_next_prime(currentPrime);
            }
            
            
            //Code to begin printing the formatted factorial output
            //First stage here prints the "N! ="
            if (userInput != 0) {
                if (userInput < 10) {
                    printf("  %d! = ", userInput);
                } else if (userInput > 99) {
                    printf("%d! = ", userInput);
                } else {
                    printf(" %d! = ", userInput);
                    
                }
                //Declaring variable to track the number of times any factor has been printed
                int numOfPrints = 0;
                
                //Second stage begins printing all the formatted prime factors of the factorial
                for (int i = 0; i < arraySize; i++) {
                    if (i == arraySize-1) {
                        printf("(%d^%d)\n\n", productArray[i][0], productArray[i][1]);
                    
                    //Special print circumstance to start a new line after 9 factors have been printed
                    } else if (numOfPrints == 8) {
                        
                        
                        printf("(%d^%d)\n", productArray[i][0], productArray[i][1]);
                        numOfPrints++;
                        
                    //Specific circumstance for beginning an indented new line
                    } else if (numOfPrints == 9) {
                        if (userInput == 100) {
                            printf("      *(%d^%d)*", productArray[i][0], productArray[i][1]);
                            numOfPrints = 0;
                            
                        } else {
                            printf("      *(%d^%d)*", productArray[i][0], productArray[i][1]);
                            numOfPrints = 0;
                            
                        }
                        //Resets the number of prints to print
                        numOfPrints = 1;
                        
                    } else {
                        //The standard circumstance for printing a prime factor
                        printf("(%d^%d)*", productArray[i][0], productArray[i][1]);
                        numOfPrints++;
                    }
                    //Ceases the main loop when the factors for this input have finished printing
                    if (i == arraySize) {
                        mainRunning = false;
                    }
                }
            }
            //Resets greenlight variable
            greenLight = false;
        }
        
    }

    //Closes the input file
    fclose(input);
    
    return 0;
}

/*
 Objective: Given any number and a prime number, calculates the number of times 
            that prime number occurs in the factorial of the input number
 Input: Function takes in two perameters, one for the input number, one for
        the prime 
 Output: Function returns one integer value, correlating to the number of times
         a given prime number occurs in the factorial of any given number
 
 */
int find_prime_count(int n, int lastPrime) {
    int frequency = 0, holdN = n, currentPrime = lastPrime;
    
    while (holdN > 1) {
        n = holdN;
        while (n % currentPrime == 0) {
            frequency ++;
            n = n / currentPrime;
        }
        
        holdN --;
        
    }
    return frequency;
}

/*
 Objective: Given any number, finds the next largest prime number
 Input: Recieves one number as a parameter, to find the next largest prime
 Output: Returns the next largest prime number as a integer
*/
int find_next_prime(int lastPrime) {
    
    //Declaring variables
    int nextPrime = 0, currentCheck = lastPrime;
    bool running = true, primeStatus;

    //Opening a loop and calculating the number of times a prime factor occurs in N!
    while (running) {
        currentCheck++;
        primeStatus = is_prime(currentCheck);
        if (primeStatus == true) {
            nextPrime = currentCheck;
            running = false;
        } else {
        }
    }
    
    //Returns the result
    return nextPrime;
}

/*
 Objective: A function to take in a number and determien if it is prime or not
 Input: Recieves one number as a parameter, to check if it is prime or not
 Output: Returns a boolean value, true if the number is prime, false if the number
            is not prime
 */
int is_prime (int number) {
    
    //Declarign a variable
    bool primeStatus = false;
    
    //Special case to return 2 as a prime number
    /*This case is needed as the way I calculate prime numbers
     will exclude 2 from beign returnd as prime */
    if (number == 2) {
        primeStatus = true;
        return primeStatus;
    }
    
    //Calculating the next prime number
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            primeStatus = false;
            return primeStatus;
        } else {
            primeStatus = true;
        }
    }
    
    //Returns the result
    return primeStatus;
}

/*
 Objective: Determine the largest number of needed prime factors in the factorial of any
            given number
 Input: Takes in one number as a parameter to calculate the ammount of prime factors
        in that numbers factorial
 Output: Returns one value, the ammount of prime factors in any given numbers factorial
 */

int calculateArraySize(int n){
    
    //Declaring variables
    bool running = true;
    int checkPrime = 2, arraySize = 0;
    
    //Opening a loop and checking if a number is prime
    while (running) {
        if (checkPrime <= n) {
            arraySize++;
            checkPrime = find_next_prime(checkPrime);
        } else {
            running = false;
            
        }
    }
    
    //Returns the result
    return arraySize;
}
