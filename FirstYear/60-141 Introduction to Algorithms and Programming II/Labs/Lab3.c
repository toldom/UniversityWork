//
//  main.c
//  Laboratory 3
//
//  Created by Marcus Toldo on 2017-01-30.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


#define M 6
#define N 5

int printArray2D(int array2D[][N]); //Prints a 2D array
int populateRandom2D(int array2D[][N]); //Pupulates an array with random numbers
bool linearSearch2D(int array2D[][N], int); //Seatches through the array, returns true
int leftShift2D(int array2D[][N]); //Left shifts the array


int main(void) {
    
    srand(time(NULL));
    
    //Declares an empty MxN 2D array
    int array2D[M][N] = {0}, userChoice, searchNum;
    
    //Declaring boolean variables to be used
    bool running = true, searchStatus;
    
    //Opens the main program loop
    while(running) {
        
        //Asks the user for their choice of opperation
        printf("1. Populate Random Array\n2. Print Array\n3. Linear Search\n4. Left Shift\n0. Terminate Program\n\n");
        scanf("%d", &userChoice);
        
        //Opens a switch statement based on user input
        switch (userChoice) {
            case 0:
                running = false;
                break;
                
            case 1:
                populateRandom2D(array2D);
                break;
                
            case 2:
                printArray2D(array2D);
                printf("\n\n");
                break;
                
            case 3:
                printf("Please enter a number to search for :");
                scanf("%d", &searchNum);
                searchStatus = linearSearch2D(array2D, searchNum);
                if (searchStatus == true) {
                    printf("The number %d is in the array\n\n", searchNum);
                } else {
                    printf("The number %d is not in the array\n\n", searchNum);
                }
                break;
                
            case 4:
                leftShift2D(array2D);
                break;
                
            default:
                break;
        }
    }
    
    return 0;
}

/*
 Objective: Populate any 2D array with dimensions MxN
 Input: Recieves the 2D array as input parameter
 Output: Returns 0 after performign the opperation on the array
 */
int populateRandom2D(int array2D[M][N]) {
    
    int limit = M*N, candNum;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            
            candNum = rand() % limit + 1;
            
            while (linearSearch2D(array2D, candNum)) {
                candNum = rand() % limit + 1;
                }

            array2D[i][j] = candNum;
        }
    }
    
    return 0;
}

/*
 Objective: Print any 2D array with dimensions MxN
 Input: Recieves the 2D array as an input parameter
 Output: Returns 0 after printing the array
 */
int printArray2D(int array2D[M][N]) {
    
    int counter = 0;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            counter ++;
            if (counter == M) {
                printf("%d   \n", array2D[i][j]);
                counter = 0;
            } else {
                if (array2D[i][j] < 10) {
                    printf("%d   ", array2D[i][j]);
                } else {
                    printf("%d  ", array2D[i][j]);

                }
            }
            
        }
    }
    return 0;
}

/*
 Objective: Search any 2D array with dimensions MxN for a certain number
 Input: Recieves the 2D array and number to search for as input parameter
 Output: Returns either true or false, depending on if the number is in the array or not
 */
bool linearSearch2D(int array2D[M][N], int testNum) {
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (testNum == array2D[i][j]) {
                return true;
            }
        }
    }
    
    return false;
}

/*
 Objective: Left shift ant MxN 2D array
 Input: Recieves any MxN matrix as input parameter
 Output: Returns 0 after performign the opperation
 */
int leftShift2D(int array2D[M][N]) {
    
    //Declares array to hope a copy of the origional
    int arrayCopy[M][N] = {0};
    
    //Copying the origional
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            arrayCopy[i][j] = array2D[i][j];
        }
    }
    
    //Hoolding the first coloumn of the array before manipulating
    int holdingArray[N] = {0};
    for (int i = 0; i < N; i ++) {
        holdingArray[i] = array2D[0][i];
    }
    
    
    
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j++) {
            array2D[i][j-1] = arrayCopy[i][j];
        }
    }
    
    array2D[M-1][N-1] = arrayCopy[0][0];
    
    
    return 0;
}
