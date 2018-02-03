//
//  main.cpp
//  toldom_Assignment1
//
//  Created by Marcus Toldo on 2018-01-29.
//  Copyright © 2018 Marcus Toldo. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

void Initialization();
void myDisplay();
void MakePixle(int x, int y);
int ProgramInitialization();

int x1, y1, x2, y2, windowW, windowH;

int main(int argc, char **argv) {
    
    ProgramInitialization();
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(windowW, windowH);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("toldom_Assignment1");
    Initialization();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}

/*                                                                                              /
/ Objective: Initialize OpenGL window, with window size as specified by the user at runtime     /
/                                                                                              */
void Initialization() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, windowW, 0, windowH);
}

/*                                                                                                  /
/ Objective:   Function that plots all the points on the display to be drawn by OpenGL. Starts off  /
/              drawing the two inputted points, P1 and P2. Will then draw horizontal and vertical   /
/              lines with a simple loop, if x1 and x2 have the same value, or if y1 and y2 have     /
/              the same value, respectively. If it is neither a horizontal or vertical line, the    /
/              line will be drawn with Bresenham's algorithm.                                       /
/                                                                                                  */
void myDisplay() {
    MakePixle(x1, y1);
    MakePixle(x2, y2);
    
    if (x1 == x2 && x2 == y2) {
        //Case for horizontal line

        std::cout << std::endl << "This is literally just a point" << std::endl;
    } else if (x1 == x2) {
        std::cout << std::endl << "Horizontal line" << std::endl;
        
        for (int i = std::min(y1, y2); i < std::max(y1, y2); i++) {
            MakePixle(x1, i);
        }
        
    } else if (y1 == y2) {
        //Case for vertical line

        std::cout << std::endl << "Vertical line" << std::endl;
        
        for (int i = std::min(x1, x2); i < std::max(x1, x2); i++) {
            MakePixle(i, y1);
        }
        
    } else {
        //Case for Breshams algorithm lines
        
        std::cout << std::endl << "Breshams Algorithm" << std::endl;
        
        int dx = x2 - x1;
        int dy = y2 - y1;
        
        if (abs(y2 - y1) < abs(x2 - x1)) {
            
            if (x1 > x2) {
                
                dx = x1 - x2;
                dy = y1 - y2;
                int yi = 1;
                if (dy < 0) {
                    yi = -1;
                    dy = -dy;
                }
                
                int delta = 2*dy - dx;
                int y = y2;

                for (int i = x2; i < x1; i++) {
                    
                    MakePixle(i, y);
                    
                    if (delta > 0) {
                        y = y + yi;
                        delta = delta - 2*dx;
                    }
                    delta = delta + 2*dy;
                }
                
            } else {
                
                dx = x2 - x1;
                dy = y2 - y1;
                int yi = 1;

                if (dy < 0) {
                    yi = -1;
                    dy = -dy;
                }
                
                int delta = 2*dy - dx;
                int y = y1;
                
                for (int i = x1; i < x2; i++) {
                    MakePixle(i, y);
                    if (delta > 0) {
                        y = y + yi;
                        delta = delta - 2*dx;
                    }
                    delta = delta + 2*dy;
                }
            }
            
        } else {
            
            if (y1 > y2) {
                
                dx = x1 - x2;
                dy = y1 - y2;
                int xi = 1;
                if (dx < 0) {
                    xi = -1;
                    dx = -dx;
                 }

                int delta = 2*dx - dy;
                int x = x2;

                for (int i = y2; i < y1; i++) {
                    MakePixle(x,i);
                    if (delta > 0) {
                        x = x + xi;
                        delta = delta - 2*dy;
                    }
                
                    delta = delta + 2*dx;
                }
            } else {
                
                dx = x2 - x1;
                dy = y2 - y1;
                int xi = 1;
                
                if (dx < 0) {
                    xi = -1;
                    dy = -dy;
                }
                
                int delta = 2*dy - dx;
                int y = y1;
                
                for (int i = x1; i < x2; i++) {
                    MakePixle(i, y);
                    if (delta > 0) {
                        y = y + xi;
                        delta = delta - 2*dx;
                    }
                    delta = delta + 2*dy;
                }
            }
            
        }
    }

    glFlush();
}

/*
 Objective: Puts a pixel on the display
 Input: Recieves an x and y coordinate as input parameters, and uses OpenGL function "glVertex2d" to display the point
 Output: Returns no value, all operations happen within the function
 */
void MakePixle(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

/*
 Objective: Initialize all the global variables for this program, including Window dimensions and coordinates for P1 and P2
 */
int ProgramInitialization() {
    
    //Getting the window dimensions from the user
    std::cout << "Please enter the dimensions for the OpenGL window..." << std::endl;
    std::cout << "Window width: ";
    std::cin >> windowW;
    std::cout << "Window height: ";
    std::cin >> windowH;
    std::cout << std::endl;
    
    //Getting the coordinates from P1 from the user
    std::cout << "Please enter the coordinated for P1..." << std::endl;
    std::cout << "P1 x: ";
    std::cin >> x1;
    std::cout << "P1 y: ";
    std::cin >> y1;
    
    //Getting the cooridnates for P2 from the user
    std::cout << std::endl << "Please enter the coordinates for P2..." << std::endl;
    std::cout << "P2 x: ";
    std::cin >> x2;
    std::cout << "P2 y: ";
    std::cin >> y2;
    
    return 0;
}
