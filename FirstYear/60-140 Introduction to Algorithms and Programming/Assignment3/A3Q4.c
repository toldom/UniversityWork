//  A3Q4.c
//  Created by Marcus Toldo on 2016-11-02.
//  Copyright © 2016 Marcus Toldo. All rights reserved.

#include <stdio.h>

int main(void) {
    
    //Question 4a)
    int n = 1, a = 1;
    if (a > n && n > 0) {
        printf("Good!");
    }
    else {
        printf("Hello!");
    }
    printf("\n\n");
    
    //Question 4b)
    int k = 1;
    while (k < 10) {
        printf("%d ", k);
        k++;
    }
    printf("\n\n");
    
    //Question 4c)
    k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k < 10);
    printf("\n\n");
    
    //Question 4d)
    float x = 10.0;
    while (x > 1.001) {
        printf("%f ", x);
        x = sqrt(x);
    }
    
    
    return 0;
}
