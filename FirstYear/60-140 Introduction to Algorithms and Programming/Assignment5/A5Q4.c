//
//  A5Q4.c
//
//  Created by Marcus Toldo on 2016-12-02.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int, int);

int main(void) {
    
    //Setting the seed for random numbers based on time
    srand(time(NULL));
    
    //Initializign and generatign random numbers for out n and m values
//    int n = rand() % 100 + 2;
//    int m = rand() % 100 + 2;
    int n = 99;
    int m = 10;
    
    //Ensuring that the n value is always larger than the m value (neccesary for program to run as intended)
    if (n < m) {
        int swap = n;
        n = m;
        m = swap;
    }
    
    //Generating the gcd value by using the function
    int greatestCommonDivisor = gcd(n, m);
    
    //Printing the final result to the user
    printf("The greatest common divisor between %d and %d is %d\n\n", n, m, greatestCommonDivisor);
    
    return 0;
}

//Function to calculate the gcd between the two random numbers n and m
int gcd(int n, int m) {
    
    if (n % m != 0) {
        return m = gcd(n, n%m);
    }
    return m;
}
