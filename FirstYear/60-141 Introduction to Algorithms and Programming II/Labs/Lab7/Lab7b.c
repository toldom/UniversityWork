//
//  Lab7b.c
//  Lab7
//
//  Created by Marcus Toldo on 2017-03-15.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct myWord {
    char Word[21];
    long Length;
};

int main(void) {
    
    struct myWord WordList[20];
    
    char myString[] = "the cat in the hat jumped over the lazy fox";
    
    char * token = strtok(myString, " ");
    
    int wordCount=0;
    
    for (int i = 0; token != NULL; i++) {
        strcpy(WordList[i].Word, token);
        WordList[i].Length = strlen(token);
        token = strtok(NULL, " ");
        printf("Word: %-*s Length: %ld\n",10, WordList[i].Word, WordList[i].Length);
        wordCount++;
    }
    
    printf("\n~~~~~~~~Bubble Sort~~~~~~~~\n\n");
    
    
    char *holdWord[256];
    long holdSize;
    for (int i = 0; i < wordCount; i++) {
        for (int j = 0; j < wordCount-1; j++) {
            if (strcmp(WordList[i].Word, WordList[j].Word) < 0) {
                strcpy(holdWord, WordList[i].Word);
                strcpy(WordList[i].Word, WordList[j].Word);
                strcpy(WordList[j].Word, holdWord);
                
                
                holdSize = WordList[i].Length;
                WordList[i].Length = WordList[j].Length;
                WordList[j].Length = holdSize;
            }

        }
    }
    
    for (int i = 0; i < wordCount; i++) {
        printf("Word: %-*s Length: %ld\n", 10, WordList[i].Word, WordList[i].Length);
    }
    
    
    return 0;
}

/*int BubbleSort(int *array, int size) {
    
    for (int i = 0; i < size-1; i++) {
        
        if (array[i] < array[i+1] ) {
            Swap(&array[i], &array[i+1]);
            i = -1;
        }
    }
    
    return 0;
}*/
