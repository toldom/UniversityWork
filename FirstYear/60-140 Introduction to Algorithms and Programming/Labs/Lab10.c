//
//  main.c
//  Lab10
//
//  Created by Marcus Toldo on 2016-12-06.
//  Copyright © 2016 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#define STACK_Size 6

int contents[STACK_Size];
int top = -1;

int isEmpty();
int isFull();
int pop();
int push(int data);

int main() {
//     push items on to the contents
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);
    
    printf("contents full: %s\n" , isFull()?"true":"false");
    printf("contents empty: %s\n" , isEmpty()?"true":"false");
    
    printf("Elements: \n");
    
    // print contents data
    while(!isEmpty()) {
        int data = pop();
        printf("%d\n",data);
    }
    
    printf("contents full: %s\n" , isFull()?"true":"false");
    printf("contents empty: %s\n" , isEmpty()?"true":"false");
    
    return 0;
}

int isEmpty() {
    
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    
    if(top == STACK_Size -1)
        return 1;
    else
        return 0;
}

int pop() {
    int data;
    
    if(!isEmpty()) {
        top = top - 1;
        data = contents[top];
        return data;
    } else {
        printf("Could not retrieve data, contents is empty.\n");
    }
    
    return 0;
}

int push(int data) {
    
    if(!isFull()) {
        contents[top] = data;
        top = top + 1;
    } else {
        printf("Could not insert data, contents is full.\n");
    }
    
    return 0;
}

