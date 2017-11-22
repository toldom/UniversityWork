//
//  main.c
//  Assignment 2
//
//  Created by Marcus Toldo on 2017-01-30.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//
//             U
//             |
//      L______|______R
//             |
//             |
//             D

#include <stdio.h>
#include <stdbool.h>

int findStart(char maze[][12]); //Function to find the opening point of a maze
int mazeTraversal(char maze[][12]); //Recursive function to move your current position throguh the maze
int validMove(char maze[][12], char); //Determines if the next move is valid or not
int printMaze(char maze[][12]); //Funtion to print the maze
int deadEndEscape(char maze[][12]); //Function used to get the current position out from being stuck in a dead end

int X = 0, Y = 0;

int main(void) {
    
    //Initionalization of the maze
    char maze[12][12] = {
        {'1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','0','0','0','1','0','0','0','0','0','0','1'},
        {'0','0','1','0','1','0','1','1','1','1','0','1'},
        {'1','1','1','0','1','0','0','0','0','1','0','1'},
        {'1','0','0','0','0','1','1','1','0','1','0','0'},
        {'1','1','1','1','0','1','0','1','0','1','0','1'},
        {'1','0','0','1','0','1','0','1','0','1','0','1'},
        {'1','1','0','1','0','1','0','1','0','1','0','1'},
        {'1','0','0','0','0','0','0','0','0','1','0','1'},
        {'1','1','1','1','1','1','0','1','1','1','0','1'},
        {'1','0','0','0','0','0','0','1','0','0','0','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1'}
    };
    
    //Sets the starting Y position based on the maze enterance
    X = findStart(maze);
    
    //Special case to terminate the program if no starting point was found
    if (X == -1) {
        printf("No valid starting position found\n");
        return 0;
    }
    
    maze[X][Y] = 'X';

    printf("This is the original maze     %c\n", maze[1][1]);
    printMaze(maze);
    printf("\n\n");
    
    mazeTraversal(maze);
    
    return 0;
}

/*
 Objective: Print out the entire 12x12 maze array with propper formatting
 Input: Passes in the maze array as a parameter
 Output: Returns 0 after sucsessfully printing the array to the console
 */
int printMaze(char maze[12][12]) {
    
    //Initializes the counter variable for tracking how many elements have been printed
    int counter = 1;
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            //Special cases for if 12 elements have been printed, and a new line needs to be printed
            if (counter == 12) {
                printf("%c\n", maze[i][j]);
                counter = 1;
            } else {
                printf("%c  ", maze[i][j]);
                counter++;
            }
        }
    }
    
    return 0;
}

/*
 Objective: Run through the first row of the maze array and find the starting point
 Input: Function recieves the maze array as an input parameter
 Output: Function returns the Y position of the starting point, or -1 if no strating point was found
 */
int findStart(char maze[12][12]) {
    
    int startPos = -1;
    
    for (int i = 0; i < 12; i++){
        if (maze[i][0] == '0') {
            startPos = i;
        }
    }
    
    return startPos;
}

/*
 Objective: Recursive function used to find the correct path through the maze
 Input: Recieves the maze and starting X and Y coordinate variables as input
 Output: Makes appropriate changes to the maze and coordinates to trace a path to the exit, returns 0 when reached
 */
int mazeTraversal(char maze[12][12]) {
    
    int UValid = 0, RValid = 0, DValid = 0, LValid = 0;
    char hold;
    bool deadEnd = false;
    
    //Determining what directions are valid paths do move in
    UValid = validMove(maze, 'u');
    RValid = validMove(maze, 'r');
    DValid = validMove(maze, 'd');
    LValid = validMove(maze, 'l');

    //Travaling down the first valid path through the maze
    if (RValid == 1) {
        Y++;
    } else if (UValid == 1) {
        X--;
    } else if (DValid == 1) {
        X++;
    } else if (LValid == 1) {
        Y--;
    } else {
        deadEnd = true;
    }
    
    if (deadEnd == true) {
        deadEndEscape(maze);
        deadEnd = false;
    }
    
    //Sets the current element to 'X', marking it as having been traveled past already
    maze[X][Y] = 'X';
    
    //Code to progress to the next step in the maze and continue through the code
    printf("Press enter to see the next step\n\n");
    scanf("%c", &hold);
    
    printMaze(maze);
    printf("\n\n");
    
    //Special case to terminate the program when it reaches the end of the maze
    if (X == 4 && Y == 11){
        return 0;
    } else {
        mazeTraversal(maze);
    }
    

    return 0;
}

/*
 Objective: Determines if the next move the program is attempting to make is valid or not
 Input: Function recieves the maze, direction that needs to be tested, and the current X and Y locations as input parameters
 Output: Function returns 1 if the move is valid, or 0 if the move is not
 */
int validMove(char maze[12][12], char testDirecton) {
    
    //Switch statement runs based on direction being tested
    switch (testDirecton) {
        case 'u':
            if (maze[X-1][Y] == '0') {
                return 1;
            } else {
                return 0;
            }
            break;
            
        case 'r':
            if (maze[X][Y+1] == '0') {
                return 1;
            } else {
                return 0;
            }
            break;
            
        case 'd':
            if (maze[X+1][Y] == '0') {
                return 1;
            } else {
                return 0;
            }
            break;

        case 'l':
            if (maze[X][Y-1] == '0') {
                return 1;
            } else {
                return 0;
            }
            break;

        default:
            break;
    }
    
    return 0;
}

/*
 Objective: If the program gets stuck in a dead end, goes backwards down the last path taken to get out
 Input: Recieves the maze, and current X and Y coordinates as input
 Output: Makes appropriate changes to coordinates and returns 0
 */
int deadEndEscape(char maze[12][12]) {
    
    int counter = 2;
    char lookDirection;
    bool running = true;
    
    if (maze[X-1][Y] == 'X') {
        lookDirection = 'u';
    } else if (maze[X][Y+1] == 'X') {
        lookDirection = 'r';
    } else if (maze[X+1][Y] == 'X') {
        lookDirection = 'd';
    } else if (maze[X][Y-1] == 'X') {
        lookDirection = 'l';
    }
    
    //Switch statement that reverts out of a dead end based on what the last direction the path came from was
    switch (lookDirection) {
        case 'u':
            while (running) {
                if (maze[X-counter][Y] == '0') {
                    X -= counter;
                    running = false;
                } else if (maze[X-counter][Y] == '1'){
                    X -= counter+1;
                    maze[X][Y] = 'g';
                    deadEndEscape(maze);
                } else {
                    counter++;
                }
            }
            break;
        case 'r':
            while(running) {
                if (maze[X][Y+counter] == '0') {
                    Y += counter;
                    running = false;
                } else if (maze[X][Y+counter] == '1') {
                    Y += counter-1;
                    maze[X][Y] = 'g';
                    deadEndEscape(maze);
                } else {
                    counter++;
                }
            }
            break;
        case 'd':
            while(running) {
                if (maze[X+counter][Y] == '0') {
                    X += counter;
                    running = false;
                } else if (maze[X+counter][Y] == '1') {
                    X += counter-1;
                    maze[X][Y] = 'g';
                    deadEndEscape(maze);
                } else {
                    counter++;
                }
            }
            break;
        case 'l':
            while (running) {
                if(maze[X][Y-counter] == '0') {
                    Y -= counter;
                    running = false;
                } else if (maze[X][Y-counter] == '1') {
                    Y -= counter+1;
                    maze[X][Y] = 'g';
                    deadEndEscape(maze);
                } else {
                    counter++;
                }
            }
            
        default:
            break;
    }
    
    
    return 0;
}
