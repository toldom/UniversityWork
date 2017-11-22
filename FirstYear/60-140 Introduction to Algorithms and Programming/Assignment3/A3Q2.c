//  A3Q2.c
//  Created by Marcus Toldo on 2016-11-02.
//  Copyright © 2016 Marcus Toldo. All rights reserved.

#include <stdio.h>

int main(void) {
    
    //Instaciating variables
    int userNum, userNum1, userNum2;
    
    //Prompting the user for a two digit number input
    printf("Please enter a two digit number: ");
    scanf("%d", &userNum);
    
    //Splitting the user input into two seperate variables
    userNum1 = userNum / 10;
    userNum2 = userNum % 10;
    
    /*Top level switch statement to print the first part of the output depending on
    the first digit of the input. Ie. When the first digit is 2, it will print
    "You entered the number twenty" */
    switch (userNum1) {
        case 1:
            /*Second switch statement that handles the special cases for 10 through 19
            Prints the entire output in one printf statement in these cases */
            switch (userNum2){
                case 0:
                    printf("You entered the number ten\n");
                    break;
                case 1:
                    printf("You entered the number eleven\n");
                    break;
                case 2:
                    printf("You entered the number twelve\n");
                    break;
                case 3:
                    printf("You entered the number thirteen\n");
                    break;
                case 4:
                    printf("You entered the number fourteen\n");
                    break;
                case 5:
                    printf("You entered the number fifteen\n");
                    break;
                case 6:
                    printf("You entered the number sixteen\n");
                    break;
                case 7:
                    printf("You entered the number seventeen\n");
                    break;
                case 8:
                    printf("You entered the number eighteen\n");
                    break;
                case 9:
                    printf("You entered the number nineteen\n");
                    break;
            }
            break;
            
        /*For all following cases of the first digit, prints "You entered the number x" where
        x is based on the value of the first digit */
        case 2:
            printf("You entered the number twenty");
            break;
        case 3:
            printf("You entered the number thirty");
            break;
        case 4:
            printf("You entered the number fourty");
            break;
        case 5:
            printf("You entered the number fifty");
            break;
        case 6:
            printf("You entered the number sixty");
            break;
        case 7:
            printf("You entered the number seventy");
            break;
        case 8:
            printf("You entered the number eighty");
            break;
        case 9:
            printf("You entered the number nintey");
            break;
    }
    
    /* Second switch statement. Finished the complete output for when the number entered
    is larger than 19. Prints the value of the second digit on the same line as the previous
    output to display the whole number in words to the user */
    switch(userNum2) {
        case 1:
            printf("-one\n");
            break;
        case 2:
            printf("-two\n");
            break;
        case 3:
            printf("-three\n");
            break;
        case 4:
            printf("-four\n");
            break;
        case 5:
            printf("-five\n");
            break;
        case 6:
            printf("-six\n");
            break;
        case 7:
            printf("-seven\n");
            break;
        case 8:
            printf("-eight\n");
            break;
        case 9:
            printf("-nine\n");
            break;
    }
    return 0;
}
