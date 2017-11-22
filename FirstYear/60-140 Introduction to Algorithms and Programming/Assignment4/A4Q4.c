//
//  A4Q4.c
//
//  Created by Marcus Toldo on 2016-11-14.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int main(void) {
   
    int i;
    int weekend[7];
    weekend[0,6] = 1, weekend[1,2,3,4,5] = 0;
    
    for (i = 0; i <= 6; i++) {
        printf("%d", weekend[i]);
    }
    
    return 0;
}
