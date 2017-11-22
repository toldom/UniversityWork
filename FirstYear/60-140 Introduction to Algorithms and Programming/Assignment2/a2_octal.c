//
//  a2_octal.c
//
//  Created by Marcus Toldo on 2016-10-21.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

int main(void) {
    //Instaciating the variable to store the user input
    int number;
    
    //Primpting the user to enter a number and storing it
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);
    
    //Printing the number back to the user in base 8
    printf("The number in Octal is %05o\n", number);
    
    return 0;
}
