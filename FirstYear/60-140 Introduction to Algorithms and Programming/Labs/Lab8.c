//
//  Lab8.c
//
//  Created by Marcus Toldo on 2016-11-22.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int readNum();
bool isPrime(int);
int findPrimeCount(int, int);

int num, prime = 2;
bool p_flag = true;

int main(void) {
    
    int input = readNum();
    int prime = 2;
    printf("%d = ", input);
    while ((input = findPrimeCount(input, prime))) {
        while (!(isPrime(++prime)));
    }
    return 0;
    
}

int readNum(void) {
    
    int num;
    bool running = true;
    
    while (running == true) {
        printf("Enter a valid number (>1): ");
        scanf("%d", &num);
        
        if (num > 1) {
          return num;
        }
        printf("Invalud number\n\n");
    }
    return 0;
}

bool isPrime(prime) {
    
    int i = 2;
    //bool p_flag = false;
    
    for (i = 2; i <= num/2; i++) {
        if (num%2 == 0 && i != num)
            return 0;
    }
    
    return 1;
}

int findPrimeCount(num, prime) {
    
    if (num == 1) return 0;
    
    int count = 0;
    
    while (num%prime==0) {
        count++;
        num /= prime;
    }
    
    if (count > 0) {
        printf("(%d^%d)", prime, count);
    }
    return num;
    
}
