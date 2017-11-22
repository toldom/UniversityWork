//
//  Lab7a.c
//  Lab7
//
//  Created by Marcus Toldo on 2017-03-13.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int AtoI(const char * str);
int StrCmp(const char *str1, const char *str2);
char * StrCpy(char * destination, const char * source);
char * StrCat(char * destination, const char*source);
char * StrChr(char * str, int character);

int main(void) {
    
    //Function 1
    char string[] = "     1998xx";
    
    int totalNum = AtoI(string);
    printf("%d\n", totalNum);
    
    //Function 2
    char str1[] = "Code";
    char str2[] = "Code";
    
    int stringCompStatus;
    
    stringCompStatus = StrCmp(str1, str2);
    if (stringCompStatus == 0) {
        printf("\nThe strings are the same\n\n");
    } else {
        printf("\nThe strings are different: %d\n\n", stringCompStatus);
    }
    
    //Function 3
    char source[] = "This is the source string";
    char destination[80];

    StrCpy(destination, source);
    printf("This is the copied string: %s\n\n", destination);
    
    //Function 4
    char secSource[256] = " world!";
    char secDestination[256] = "Hello there";
    
    printf("Source string: %s\nDestination string: %s\n", secSource, secDestination);
    StrCat(secDestination, secSource);
    printf("Catonized string: %s", secDestination);
    
    //Function5
    char thirdString[] = "aaaHello";
    printf("\n\nThe pushed string is: %s\n\n", StrChr(thirdString, 'H'));
    
    return 0;
}

/*
 Objective: Take a string of integers in character form and return the actual integer representation
 Input: Recieves a pointer to a string to get the integer value from
 Output: If the program encounters a letter before any numbers, returns 0, or else it returns an int value representative of the char numbers found in the string
 */
int AtoI(const char*str) {
    
    int totalNum = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        while (isspace(*str) ) str++;
        
        
        if (isalpha(*str) == 1) return 0;
        
        switch (str[i]) {
            case '1':
                totalNum = totalNum*10;
                totalNum += 1;
                break;
            case '2':
                totalNum = totalNum*10;
                totalNum+= 2;
                break;
            case '3':
                totalNum = totalNum*10;
                totalNum += 3;
                break;
            case '4':
                totalNum = totalNum*10;
                totalNum += 4;
                break;
            case '5':
                totalNum = totalNum*10;
                totalNum += 5;
                break;
            case '6':
                totalNum = totalNum*10;
                totalNum += 6;
                break;
            case '7':
                totalNum = totalNum*10;
                totalNum += 7;
                break;
            case '8':
                totalNum = totalNum*10;
                totalNum += 8;
                break;
            case '9':
                totalNum = totalNum*10;
                totalNum += 9;
                break;
            case '0':
                totalNum = totalNum*10;
                totalNum += 0;
                break;
                
            default:
                break;
        }
    }
    
    return totalNum;
}

/*
 Objective: Check if two strings are the same
 Input: Recieves two strings as input to check
 Output: Returns 0 if the two strings are the same. If they are not the same, return either 1 or -1 based on ASCII values of the first divergent chars
 */
int StrCmp(const char * str1, const char * str2) {
    
    long str1Len = strlen(str1);
    
    for (int i = 0; i < str1Len; i++) {
        if (str1[i] != str2[i]) {
            
            int a = str1[i], b = str2[i];
            
            if (a > b) {
                return -1;
            } else {
                return 1;
            }
            
        }
    }
    
    return 0;
}

/*
 Objective: Copy one string onto another
 Input: Recieves two strings as input, one as the destination and another as the source
 Output: Returns the destination string after being copied
 */
char * StrCpy(char * destination, const char * source) {
    
    int i;
    
    for (i = 0; source[i] != '\0'; i++) {
        
        destination[i] = source[i];
    }

    destination[i] = '\0';

    return destination;
}

/*
 Objective: Append a source string onto the end of the destination string
 Input: Recieves two strings as input
 Output: Returns the catonized string
 */
char * StrCat(char * catDestination, const char * catSource) {
    
    long destLen = strlen(catDestination), sourceLen = strlen(catSource);
    
    catDestination[destLen] = ' ';
    
    for (long i = destLen, j = 0; j < sourceLen; i++, j++) {
        catDestination[i] = catSource[j];
    }
    
    return catDestination;
}

/*
 Objectice: Return a pointer to the rest of the string as of a specified char
 Input: Recieves a string and a char as inputs
 Output: Returns the pointer to the new starting position of the string 
 */
char * StrChr(char * str, int character){
    
    long strLen = strlen(str);
    int holdPos = 0;
    
    for (int i = 0; i < strLen; i++) {
        if (str[i] == character) {
            holdPos = i;
            break;
        }
    }
    
    return str+holdPos;
}
