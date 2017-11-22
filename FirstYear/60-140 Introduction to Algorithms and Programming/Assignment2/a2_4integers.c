//
//  a2_4integers.c
//
//  Created by Marcus Toldo on 2016-10-21.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    //Instaciating a list of four integers
    int x[4];
    
    //Primpting the user to enter four integers, to be assignes to their respective places in the array
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &x[0], &x[1], &x[2], &x[3]);
    
    //Assigning the default largest and smallest values to the first item in the array
    int largest = x[0];
    int smallest = x[0];

    //First for loop to determine the actual largest value in the array
    //Runs thoguh the aray as many times as there are items, comparing if the current item is larger than the last
    //If the current item is larger than the last, stores the current item as the new maximum
    for (int i = 0; i < 4; i++) {
        if (x[i] > largest) {
            largest = x[i];
        }
    }
    
    //Second for loop to determine the actual smallest value in the array
    //Runs theough the aray as many times as thee are items, compating if the current item is smaller than the last
    //If the current item us smaller than the last, stores the current item as the new maximun
    for (int i = 0; i < 4; i++) {
        if (x[i] < smallest) {
            smallest = x[i];
        }
    }
    
    //Prints out the maximum and minumum values from the array to the user
    printf("\nThe largest number of the numbers is %d, the smallest of the numbers is %d\n", largest, smallest);
    
    return 0;
}
