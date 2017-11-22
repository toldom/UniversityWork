//
//  main.c
//  Lab6
//
//  Created by Marcus Toldo on 2017-03-06.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void Reverse(char array[]); //Prototype for the Reverse function
int ParseSentence(char S[]); //Prototype for the ParseSentence function

int main(void) {
    
    //Initializing and defining the strings buffer1 and buffer2, initializing buffer3
    char buffer1[] = {'t', 'h', 'i', 's', ' ', 'i', 's', ' ' , 't', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r', '\0'};
    char buffer2[] = "this is the second buffer";
    char buffer3[80];
    
    //Initilizing a pointer to buffer3
    char * pBuffer = buffer3;
    
    //Prompting the user to input a string to be stored in buffer 3
    printf("Type something to be held in buffer 3: ");
    scanf("%s", buffer3);
    
    //Printing the three buffers
    printf("\nbuffer1: %s", buffer1);
    printf("\nbuffer2: %s", buffer2);
    printf("\nbuffer3: %s", buffer3);
    
    //Printing buffer3 through its pointer
    printf("\n\npointer buffer3: %s", *&pBuffer);
    
    //Printing 2 characters advanced into buffer3, with pointer manipulation
    printf("\n\nadvanced pBuffer: %s", pBuffer+2);
    
    //Running buffer3 theough the reverse function to reverse it
    Reverse(buffer3);
    
    //Printing the reversed buffer3
    printf("\n\nThe reverse of buffer3 is: %s\n\n", buffer3);
    
    char S[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    char K[] = "Today is Wednesday tomorrow will be Thursday yesterday was Tuesday";
    
    ParseSentence(K);
    
    return 0;
}

/*
 Objective: Take an inputted string and reverse its characters
 Input: Recieves an array of any size as input parameter
 Output: Returns nothing, as a void function, but manipulates the string within the function
 */
void Reverse(char array[]) {
    
    int running = 1, counter = 0, point = 0;
    char holder;
    
    while (running) {
        if (array[point] != '\0') {
            point++;
            counter++;
        } else {
            running = 0;
        }
    }
    
    counter--;
    
    for (int i = 0; i < floor(counter/2); i++) {
        holder = array[i];
        array[0 + i] = array[counter - i];
        array[counter - i] = holder;
    }
    
    return;
}

/*
 Objective: Tokenize a given string and print eacn word in it on a new line
 */
int ParseSentence(char S[]) {
    
    const char delim[2] = {" "};
    char *token;
    
    token = strtok(S, delim);
    
    while (token != NULL) {
        printf("%s\n", token);
        
        token = strtok(NULL, delim);
    }
    
    /*int limit = 0, counter, running = 1, point = 0, alreadySplit = 0;
    
    while (running) {
        if (S[point] != '\0') {
            point++;
            counter++;
        } else {
            running = 0;
        }
    }
    
    running = 1;
    
    for (int i = 0; i < counter; i++) {
        if (running == 1) {
            if (S[i] == ' ' || S[i] == ',' || S[i] == ';' || S[i] == '.') {
                limit = i;
                running = 0;
            }
        }
        
    }
    
    char newArray[] = {};
    
    for (int i = 0; i < limit; i++) {
        newArray[i] = S[i];
    }
    
    newArray[limit+1] = '\0';
    
    printf("%s", newArray);
    
    running = 1;
    
    if (alreadySplit) {
        for (int i = 0; running; i++) {
            if (S[i] != '\0') {
                
            }
        }
    }*/
    
    
    return 0;
}
