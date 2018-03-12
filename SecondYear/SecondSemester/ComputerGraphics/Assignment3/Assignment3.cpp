/*                                            /
/   03-06-352  -  Intro to Computer Graphics  /
/   Assignment 3 - 3D House                   /
/   Marcus Toldo - 104623006                  /
/   Wednesday, March 7, 2018                  /
/                                            */

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <stdlib.h>

GLfloat camX = 0.0, camY = 0.0, camZ = 10.0;

void init();
void display();
void createMenu();
void menu(int);
void mouseFunction(int, int, int, int);


int main (int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("toldom Assignment 3");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glutMouseFunc(mouseFunction);
    glutDisplayFunc(display);
    
    createMenu();
    
    glutMainLoop();
    
    return 0;
}

void display() {
    
    static int done = 0;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, 640.0/480.0, 1.0, 25.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    if (done) {
        glCallList(1);
    } else {
        done = 1;
        glNewList(1, GL_COMPILE_AND_EXECUTE);
        
        //Quads for sides of the house
        glBegin(GL_QUADS);
        //Front wall - light blue
        glColor3f(0.39, 0.39, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);

        
        //Left side wall - light green
        glColor3f(0.39, 1.0, 0.39);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        
        //Back wall - black
        glColor3f(0, 0, 0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.0, -1.0, -1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        
        //right side wall - light red
        glColor3f(1.0, 0.39, 0.39);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glVertex3f(1.0, -1.0, -1.0);
        
        //bottom side - orange
        glColor3f(1.0, 0.59, 0.0);
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(1.0, -1.0, -1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        
        glEnd();
        
        //Triangles for roof
        glBegin(GL_TRIANGLES);
        
        //Front roof slant - FULL RED
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(0.0, 2.0, 0.0);
        glVertex3f(1.0, 1.0, 1.0);
        
        //right roof slant - Purple
        glColor3f(0.59, 0.0, 0.59);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(0.0, 2.0, 0.0);
        glVertex3f(1.0, 1.0, -1.0);

        //left roof slant - cyan
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(0.0, 2.0, 0.0);
        glVertex3f(-1.0, 1.0, -1.0);
        
        //back roof slant - brown
        glColor3f(0.55, 0.27, 0.07);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 2.0, 0.0);
        glVertex3f(1.0, 1.0, -1.0);
        
        glEnd();
        
        glBegin(GL_QUADS);
        
        //Front door - brown
        glVertex3f(-0.25, -1, 1.01);
        glVertex3f(-0.25, -0.25, 1.01);
        glVertex3f(0.25, -0.25, 1.01);
        glVertex3f(0.25, -1, 1.01);
        
        //front window left - light blue
        glColor3f(0.59, 0.59, 0.94);
        glVertex3f(-0.75, 0.75, 1.01);
        glVertex3f(-0.25, 0.75, 1.01);
        glVertex3f(-0.25, 0.25, 1.01);
        glVertex3f(-0.75, 0.25, 1.01);
        
        //front window right - light blue
        glVertex3f(0.25, 0.75, 1.01);
        glVertex3f(0.75, 0.75, 1.01);
        glVertex3f(0.75, 0.25, 1.01);
        glVertex3f(0.25, 0.25, 1.01);
        
        //left bottom window - light blue
        glVertex3f(-1.01, -0.25, 0.20);
        glVertex3f(-1.01, -0.25, 0.80);
        glVertex3f(-1.01, -0.5, 0.80);
        glVertex3f(-1.01, -0.5, 0.20);
        
        //left top window - light blue
        glVertex3f(-1.01, 0.25, -0.20);
        glVertex3f(-1.01, 0.25, -0.80);
        glVertex3f(-1.01, 0.5, -0.80);
        glVertex3f(-1.01, 0.5, -0.20);
        
        //chimney
        //front - black
        glColor3f(0, 0, 0);
        glVertex3f(-0.7, 1.0, -0.8);
        glVertex3f(-0.6, 1.0, -0.8);
        glVertex3f(-0.6, 2.0, -0.8);
        glVertex3f(-0.7, 2.0, -0.8);
        
        //left side - black
        glVertex3f(-0.7, 1.0, -0.8);
        glVertex3f(-0.7, 2.0, -0.8);
        glVertex3f(-0.7, 2.0, -0.9);
        glVertex3f(-0.7, 1.0, -0.9);
        
        //back side - black
        glVertex3f(-0.7, 1.0, -0.9);
        glVertex3f(-0.7, 2.0, -0.9);
        glVertex3f(-0.6, 2.0, -0.9);
        glVertex3f(-0.6, 1.0, -0.9);
        
        //left side - black
        glVertex3f(-0.6, 1.0, -0.9);
        glVertex3f(-0.6, 2.0, -0.9);
        glVertex3f(-0.6, 2.0, -0.8);
        glVertex3f(-0.6, 1.0, -0.8);
        
        
        glEnd();
        
        glEndList();
        
    }
    
    glutSwapBuffers();
    
}

void createMenu() {
    glutCreateMenu(menu);
    glutAddMenuEntry("Increment X", 0);
    glutAddMenuEntry("De-Increment X", 1);
    glutAddMenuEntry("Increment Y", 2);
    glutAddMenuEntry("De-Increment Y", 3);
    glutAddMenuEntry("Increment Z", 4);
    glutAddMenuEntry("De-Increment Z", 5);
    glutAddMenuEntry("Reset Camera", 6);
    glutAddMenuEntry("Exit", 7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/*
 / Purpose: Function performs code for the right click menu
 */
void menu(int n) {
    
    switch (n) {
        case 0:
            camX += 6;
            break;
            
        case 1:
            camX -= 6;
            break;
            
        case 2:
            camY += 6;
            break;
            
        case 3:
            camY -= 6;
            break;
            
        case 4:
            camZ += 6;
            break;
            
        case 5:
            camZ -= 6;
            break;
            
        case 6:
            camX = 0;
            camY = 0;
            camZ = 10;
            break;
            
        case 7:
            exit(0);
            break;
            
        default:
            break;
    }
    
    display();
}

/*
 / Description: Code to handle left mouse click camera positioning
 */
void mouseFunction(int button, int state, int posX, int posY) {
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        camX = posX/50 - 5;
        camY = posY/50 - 5;
    }
    display();
}

