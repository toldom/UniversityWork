//
//  exprEval.c
//
//  Created by Marcus Toldo on 2016-10-25.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

int main(void) {
    
    //Instaciating variables for the opperation and the two values
    char opp;
    float valOne;
    float valTwo;
    float resultValue;
    
    while (1){
        printf("\nEnter a simple expression: ");
        scanf("%f %c %f", &valOne, &opp, &valTwo);
        
        if (opp == '+') {
            resultValue = valOne + valTwo;
            printf("Output: %.2f + %.2f = %.2f \n", valOne, valTwo, resultValue);
        } else if (opp == '-') {
            resultValue = valOne - valTwo;
            printf("Output: %.2f - %.2f = %.2f \n", valOne, valTwo, resultValue);
        } else if (opp == '*') {
            resultValue = valOne * valTwo;
            printf("Output: %.2f * %.2f = %.2f \n", valOne, valTwo, resultValue);
        } else if (opp == '/') {
            if (valTwo == 0) {
                printf("Output: You cannot divide by zero!\n");
            } else {
                resultValue = valOne / valTwo;
                printf("Output: %.2f / %.2f = %.2f \n", valOne, valTwo, resultValue);
            }
        } else {
            printf("Output: Unknown operator! \n");
            }
        }
    
    return 0;
    
}
