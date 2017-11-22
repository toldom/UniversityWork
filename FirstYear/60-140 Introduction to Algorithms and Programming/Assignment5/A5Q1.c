//
//  A5Q1.c
//
//  Created by Marcus Toldo on 2016-11-29.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

double triangle_area(double base, double height);

int main(void) {
    
    double product = triangle_area(5, 7);
    printf("%f", product);
    
    return 0;
}

/* ORIGIONAL PROGRAM CODE

double triangle area(double base, height) 
double product;
{
    product = base * height;
    return product / 2;
} 
*/

/*FIXED PROGRAM CODE */

double triangle_area(double base, double height) {
    double product;

    product = base * height;
    return product / 2;
}
