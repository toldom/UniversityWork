//
//  main.c
//  Lab5
//
//  Created by Marcus Toldo on 2017-02-27.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int FillArray(int *array, int); //
int PrintArray(int *array, int);
int BubbleSort(int *array, int);
void Swap(int *x, int *y);

int size;
size = 20;

int main(void) {
   
    int array[20] = {0};
    
    FillArray(array, size);
    
    PrintArray(array, size);
    
    printf("\n\n");
    
    BubbleSort(array, size);
    
    PrintArray(array, size);
    
    return 0;
}
/*
 Purpose: Populate the array with random numbers
 Input: Recieves the array and size of the array as input parameters
 Output: Returns 0 upon soccsessful completion
 */
int FillArray(int *array, int size) {
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 99 + 1;
    }
    
    return 0;
}

/*
 Purpose: Prints the array
 Input: Recieves the array and size of the array as input parameters
 Output: Returns 0 uppon sucsessful completion
 */
int PrintArray(int *array, int size) {
    
    for (int i = 0; i < size; i++) {
        printf("%d \n", array[i]);
    }
    
    return 0;
}

/*
 Purpose: Bubble sort the array
 Input: Takes the array and size of the array as input parameters
 Output: Returns 0 upon succsessful completion
 */
int BubbleSort(int *array, int size) {
    
    for (int i = 0; i < size-1; i++) {
        
        if (array[i] < array[i+1] ) {
            Swap(&array[i], &array[i+1]);
            i = -1;
        }
    }
    
    return 0;
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
