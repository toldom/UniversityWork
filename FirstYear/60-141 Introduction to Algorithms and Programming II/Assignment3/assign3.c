//
//  main.c
//  Assignment3
//
//  Created by Marcus Toldo on 2017-03-09.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int letterAnalysis(int, char arrayOfLines[10][80]);
int stringSize(char stringBuffer[]);
int wordLengthAnalysis(int, int, char arrayOfLines[10][80]);
int wordAnalysis(int, char arrayOfLines[10][80]);


int main(void) {
    
    char arrayOfLines[10][80] = {'\0'};
    
    int numberOfLines;
    
    //Getting number of lines as input
    printf("enter a number dingus: ");
    scanf("%d", &numberOfLines);
    
    if (numberOfLines < 1 || numberOfLines > 10) {
        return 0;
    }
     
    //Scanning in inputs to the 2D array holding all inputs for as many lines as you need
    for (int i = 0; i < numberOfLines; i++) {
        scanf(" %[^\n]s", arrayOfLines[i]);
    }
    
    letterAnalysis(numberOfLines, arrayOfLines);
   
    //Calling the word length analysis funciton 3 times as neccesary
    int ammountOfWords = wordLengthAnalysis(numberOfLines, 2, arrayOfLines);
    printf("\n\n%d words of lenght 2", ammountOfWords);
    
    ammountOfWords = wordLengthAnalysis(numberOfLines, 3, arrayOfLines);
    printf("\n%d words of length 3", ammountOfWords);
    
    ammountOfWords = wordLengthAnalysis(numberOfLines, 4, arrayOfLines);
    printf("\n%d words of length 4", ammountOfWords);


    //Rip
   //wordAnalysis(numberOfLines, arrayOfLines);
    
    return 0;
}

/*
 Objective: Print out how many times each letter of the alphabet occurs in the given input sentences
 Input: Function recieves the number of lines the program has recieved as input, and the 2D array which holds the inputted lines
 Output: Returns 0, but within the funciton counts how many times every letter occurs in the inputs and prints the outcom within the function
 */
int letterAnalysis (int numberOfLines, char arrayOfLines[10][80]) {
    
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
    
    for (int I = 0; I < numberOfLines; I++) {
        
        for (int J = 0; arrayOfLines[I][J] != '\0'; J++) {
            //Switch statement for every letter of the alphabet
            switch (tolower(arrayOfLines[I][J])) {
                case 'a':
                    a++;
                    break;
                    
                case 'b':
                    b++;
                    break;
                    
                case 'c':
                    c++;
                    break;
                    
                case 'd':
                    d++;
                    break;
                    
                case 'e':
                    e++;
                    break;
                    
                case 'f':
                    f++;
                    break;
                    
                case 'g':
                    g++;
                    break;
                    
                case 'h':
                    h++;
                    break;
                    
                case 'i':
                    i++;
                    break;
                    
                case 'j':
                    j++;
                    break;
                    
                case 'k':
                    k++;
                    break;
                    
                case 'l':
                    l++;
                    break;
                    
                case 'm':
                    m++;
                    break;
                    
                case 'n':
                    n++;
                    break;
                    
                case 'o':
                    o++;
                    break;
                    
                case 'p':
                    p++;
                    break;
                    
                case 'q':
                    q++;
                    break;
                    
                case 'r':
                    r++;
                    break;
                    
                case 's':
                    s++;
                    break;
                    
                case 't':
                    t++;
                    break;
                    
                case 'u':
                    u++;
                    break;
                    
                case 'v':
                    v++;
                    break;
                    
                case 'w':
                    w++;
                    break;
                    
                case 'x':
                    x++;
                    break;
                    
                case 'y':
                    y++;
                    break;
                    
                case 'z':
                    z++;
                    break;
                    
                default:
                    break;
            }
            
        }
        
    }
    
    printf("\n\nTotal letter counts: \n");
    printf("a: %d\nb: %d\nc: %d\nd: %d\ne: %d\nf: %d\ng: %d\nh: %d\ni: %d\nj: %d\nk: %d\nl: %d\nm: %d\nn: %d\no: %d\np: %d\nq: %d\nr: %d\ns: %d\nt: %d\nu: %d\nv: %d\nw: %d\nx: %d\ny: %d\nz: %d", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);
    
    return 0;
}

/*
 Objective: Get the size of a string and return it as an int value
 Input: Recieves a 1D char array as input
 Output: Returns an int value for the lenght of the string
 */
int stringSize(char stringBuffer[]) {
    
    int size = 0;
    
    for (int i = 0; stringBuffer[i] != '\0'; i++) {
        size++;
    }
    
    return size;
}

/*
 Objective: Get the number of times words of a given length occur in all input strings
 Input: Recieves the lenght that is being looked for, number of input lines, and 2D array holding all the data
 Output: Returns the int value for how many times words of a certain lenght occur in the inputs
 */
int wordLengthAnalysis(int numberOfLines, int length, char arrayOfLines[10][80]) {
    
    int lastPos = 0, ammountOfWords = 0, stringLen;
    
    //main for loop
    for (int i = 0; i < numberOfLines; i++) {
        
        stringLen = stringSize(arrayOfLines[i]);
        lastPos = 0;
        
        //Special case for the first word of each string
        if (i == 0) {
            for (int j = 0; j < stringLen+1; j++) {
                
                if (arrayOfLines[i][j] == ' ' || arrayOfLines[i][j] == '\0') {
                    
                    if (j == length) {
                        
                        ammountOfWords++;
                        lastPos = j+1;
                        j = stringLen+1;
                    } else {
                        
                        lastPos = j+1;
                        j = stringLen+1;
                    }
                }
            }
        }
        
        //General case for the rest of the string
        for (int j = lastPos; j < stringLen+1; j++) {
            if (arrayOfLines[i][j] == ' ' || arrayOfLines[i][j] == '\0') {
                if (j - lastPos == length) {
                    ammountOfWords++;
                    lastPos = j+1;
                } else {
                    lastPos = j+1;
                }
            }
        }
        
    
    }
    
    return ammountOfWords;
}

/*
 Objective: Print out how many times all words in the inputted strings occur individually
 Input: Recieves the number of input lines and input array as parameters
 Output: Returns 0 but prints all needed info in the process
 */

//Ran out of time #ThereWasAnAttempt
/*int wordAnalysis(int numberOfLines, char arrayOfLines[10][80]) {
    
    const char *delim = (" \n\r\t");
    char *IndividualWords = NULL, wordsArray[10*20];
    
    int lastPos = 0, recurrences = 0;
    
    for (int i = 0; i < numberOfLines; i++) {
        
        IndividualWords = strtok(arrayOfLines[i], delim);
        
        while (IndividualWords != NULL) {
            wordsArray[lastPos] = *IndividualWords;
            
            IndividualWords = strtok(NULL, delim);
            lastPos++;
        }
        
    }
    
    printf("Total words count: ");
    
    for (int i = 0; i < lastPos-1; i++) {
        for (int j = 0; j < lastPos-1; j++) {
            if (strcmp(&IndividualWords[i], &IndividualWords[j]) == 0 && strcmp(&IndividualWords[j], "-1") != 0) {
                recurrences++;
            }
        }
        
        printf("\"%c\"\t", IndividualWords[i]);
        
        if (strlen(IndividualWords[i] < 6)) {
            printf("\t");
        }
        
        
        printf("appeared %d time(s)", recurrences);
        
        recurrences = 0;
    
    }
    
    
    
    return 0;
}*/
