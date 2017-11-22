//
//  Lab5.c
//
//  Created by Marcus Toldo on 2016-11-01.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    
    //Setting the seed for the random number
    srand(time(NULL));

    //Declaring variables to be used in the program
    //"Correct Value" is a random number between 1 and 50
    int running = 1, correctValue = rand() % 50 + 1, userInput;
    
    //Opening the while loop that runs while our "running" value is on
    while (running == 1) {
        //Prompts the user to enter their guess and saves the input
        printf("Please enter a number between 1 and 50: ");
        scanf("%d", &userInput);
        
        //Checks the user input against the actual random number
        //Prints too low if the users guess is too low
        if (userInput < correctValue) {
            printf("Too low...\n\n");
        }
        //Prints too high is the users guess is too high
        else if (userInput > correctValue) {
            printf("Too high...\n\n");
        }
        //Prints correct, and the correct number, if the user guessed properly
        else if (userInput == correctValue) {
            printf("Correct! The correct number was %d\n\n", correctValue);
            //Turns off the loop, ending the program, when the user guesses correctly
            running = 0;
        }
    }
    
    return 0;
}
