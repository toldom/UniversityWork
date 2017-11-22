//
//  main.c
//  Lab4
//
//  Created by Marcus Toldo on 2017-02-13.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

/*
 \/\/\Question 1\/\/\
 "*Salary = 200
 Salary1 = 20,000
 Salary2 = 60,000
 Salary4 = 2008"
 */

int *Largest(int *array);
void Swap(int *x, int *y);

int main(void) {
    
    int array[10] = {8, 4, 2, 6, 9, 3, 77, 32}, x = 6, y = 3, address;
    
    address = *Largest(array);
    
    printf("%p\n", &address);
    printf("%d\n\n", address);

    
    printf("x = %d, y = %d\n", x, y);
    
    Swap(&x, &y);
    
    printf("x = %d, y = %d\n", x, y);
    
    return 0;
}

/*
 Objective: Return the memory address of the largest value in the given array
 Input: Recieves a 10 element array as input parameter
 Output: Returns the memory address of the largest element of the given array
 */
int *Largest(int *array) {
    
    int largestValue = 0;
    
    for (int i = 1; i < 10; i++) {
        if (array[largestValue] < *(array+i)) {
            largestValue = i;
        }
    }
    
    return &array[largestValue];
}

/*
 Objective: Swap two integer value variables through their pointers
 Input: Recieves the pointers of two integrers
 Output: Void funciton, returns nothing
 */
void Swap(int *x, int *y) {
    
    int hold;
    
    hold = *x;
    *x = *y;
    *y = hold;
    
    return;
}
