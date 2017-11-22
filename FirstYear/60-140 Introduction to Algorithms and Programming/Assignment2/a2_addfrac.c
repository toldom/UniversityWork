//
//  a2_addfrac.c
//
//  Created by Marcus Toldo on 2016-10-21.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

int main(void) {
    //Instaciating integer variables for the numerators and denominators of two fractions
    int num1, denom1, num2, denom2, result_num, result_denom;
    
    //Prompting the user to input both fractions
    printf("Enter the two fraction: ");
    scanf("%d/%d + %d/%d", &num1, &denom1, &num2, & denom2);
    
    
    //Calculating the result of the addition
    result_num = num1*denom2 + num2*denom1;
    result_denom = denom1 * denom2;
    
    //Printing the result of the addition to the user
    printf("The sum of is %d/%d\n", result_num, result_denom);
    
    return 0;
}
