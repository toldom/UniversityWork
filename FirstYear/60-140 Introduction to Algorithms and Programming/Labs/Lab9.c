//
//  Lab9.c
//
//  Created by Marcus Toldo on 2016-11-23.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int readNum(void);
int iterativeTriangularNumber(int);
int recursiveTriangularNumber(int);

int userNum;
int iterTriangularNumber;
int recurTriangularNumber = 0;

int main(void) {
    
    userNum = readNum();

    iterTriangularNumber = iterativeTriangularNumber(userNum);
    printf("\nIterative: Triangular number of %d is %d\n\n", userNum, iterTriangularNumber);
    
    recurTriangularNumber = recursiveTriangularNumber(userNum);
    printf("Recursive: Triagular number if %d is %d\n\n", userNum, recurTriangularNumber);
    
    return 0;
}

int readNum (void) {
    
    int userNum = 0;
    bool running = true;
    
    while (running == true) {
        printf("Please enter a number (>0): ");
        scanf("%d", &userNum);
        
        if (userNum > 0) {
            running = false;
        } else {
            printf("Invalid number!\n\n");
        }
    }
    return userNum;
}

int iterativeTriangularNumber(int userNum) {
    
    int i;
    
    for (i = 1; i <= userNum; i++) {
        iterTriangularNumber += i;
    }
    
    return iterTriangularNumber;
}

int recursiveTriangularNumber (int userNum) {
    
    if (userNum == 1) {
        return 1;
    }
    
    return userNum + recursiveTriangularNumber(userNum-1);
}
