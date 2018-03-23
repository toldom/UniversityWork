 /*                                            /
 /   03-06-352  -  Intro to Computer Graphics  /
 /   Assignment 4 - 3D House++                 /
 /   Marcus Toldo - 104623006                  /
 /   Wednesday, March 22, 2018                 /
 /                                            */

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <stdlib.h>

GLfloat camX = 0.0, camY = 2.5, camZ = 20;

void init();
void display();
void DrawHouse();
void DrawTree();
void DrawRoads();
void createMenu();
void menu(int);
void mouseFunction(int, int, int, int);


int main (int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("toldom Assignment 4");
    
    glClearColor(0.59, 0.67, 1.0, 1.0);

    glEnable(GL_DEPTH_TEST);
    
    //New glEnables for lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    
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
    gluPerspective(40.0, 640.0/480.0, 1.0, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    if (done) {
        glCallList(1);
    } else {
        done = 1;
        glNewList(1, GL_COMPILE_AND_EXECUTE);
        
        //Ambient Light
        GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
        
        //Light0 -- Position
        GLfloat LightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
        GLfloat LightPosition0[] = {0.0f, 10.0f, 0.0f, 1.0f};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, LightColor0);
        glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0);
        
        //Light1 -- Directional
        GLfloat LightColor1[] = {1.0f, 1.0f, 0.0f, 1.0f};
        GLfloat LightPosition1[] = {-2.0f, 6.0f, 0.0f, 0.0f};
        glLightfv(GL_LIGHT1, GL_DIFFUSE, LightColor1);
        glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);

        
        DrawHouse();
        DrawTree();
        DrawRoads();
        
        //Drawing Sun
        glColor3f(0.9, 0.9, 0.0);
        glTranslatef(-5, 5.0, -10);
        glutSolidSphere(0.5, 50, 50);
        
        //Drawing Clouds
        glColor3f(1, 1, 1);
        glTranslatef(14, 0, -20);
        glutSolidSphere(2, 50, 50);
        
        glTranslatef(2.5, 0.5, 0);
        glutSolidSphere(2.5, 50, 50);
        
        glTranslatef(2.5, 0.5, 0);
        glutSolidSphere(3, 50, 50);
        
        glEndList();
        
    }
    
    glutSwapBuffers();
    
}

void DrawHouse() {
    
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
    
    //"grass" - green
    glColor3f(0.0, 0.65, 0.0);
    glVertex3f(-10000.0, -1.0, -10000.0);
    glVertex3f(10000.0, -1.0, -10000.0);
    glVertex3f(10000.0, -1.0, 10000.0);
    glVertex3f(-10000.0, -1.0, 10000.0);
    
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
    
}

void DrawTree() {
    
    glBegin(GL_QUADS);
    
    //Tree Trunk START front -- Brown
    glColor3f(0.5, 0.35, 0.05);
    glVertex3f(-3.0, -1.0, 4.0);
    glVertex3f(-3.0, 2.0, 4.0);
    glVertex3f(-2.5, 2.0, 4.0);
    glVertex3f(-2.5, -1.0, 4.0);
    
    //Tree Trunk Right -- Brown
    glVertex3f(-2.5, -1.0, 4.0);
    glVertex3f(-2.5, 2.0, 4.0);
    glVertex3f(-2.5, 2.0, 3.5);
    glVertex3f(-2.5, -1.0, 3.5);
    
    //Tree Trunk Back -- Brown
    glVertex3f(-2.5, -1.0, 3.5);
    glVertex3f(-2.5, 2.0, 3.5);
    glVertex3f(-3.0, 2.0, 3.5);
    glVertex3f(-3.0, -1.0, 3.5);
    
    //Tree Trunk Left -- Brown
    glVertex3f(-3.0, -1.0, 3.5);
    glVertex3f(-3.0, 2.0, 3.5);
    glVertex3f(-3.0, 2.0, 4.0);
    glVertex3f(-3.0, -1.0, 4.0);
    
    glEnd();
    
    glColor3f(0.0, 0.90, 0.0);
    glTranslatef(-2.75, 2.0, 3.75);
    glutSolidSphere(1.2, 50.0, 50.0);

}

void DrawRoads() {
    glBegin(GL_QUADS);
    
    //Road 1 -- Black
    glColor3f(0, 0, 0);
    glVertex3f(-3.0, -2.999, -10000.0);
    glVertex3f(-5.0, -2.999, -10000.0);
    glVertex3f(-5.0, -2.999, 10000.0);
    glVertex3f(-3.0, -2.999, 10000.0);
    
    //Road 2 -- Black
    glVertex3f(-10, -2.999, 3);
    glVertex3f(200, -2.999, 3);
    glVertex3f(200, -2.999, 5);
    glVertex3f(-10, -2.999, 5);
    
    //Road Lines 1 -- Yellow
    glColor3f(1, 1, 0);
    for (int i = -100; i < 20; i+=5) {
        glVertex3f(-3.9, -2.99, i);
        glVertex3f(-4.1, -2.99, i);
        glVertex3f(-4.1, -2.99, i+2);
        glVertex3f(-3.9, -2.99, i+2);
    }
    
    //Road Lines 2 -- Yellow
    for (int i = -20; i < 20; i+=5) {
        glVertex3f(i, -2.99, 3.9);
        glVertex3f(i+2, -2.99, 3.9);
        glVertex3f(i+2, -2.99, 4.1);
        glVertex3f(i, -2.99, 4.1);
        
    }
    
    glEnd();
    
}

void createMenu() {
    glutCreateMenu(menu);
    glutAddMenuEntry("Enable Lighting", 0);
    glutAddMenuEntry("Disable Lighting", 1);
    glutAddMenuEntry("Enable Light 0", 2);
    glutAddMenuEntry("Disable Light 0", 3);
    glutAddMenuEntry("Enable Light 1", 4);
    glutAddMenuEntry("Disable Light 1", 5);
    glutAddMenuEntry("Increment Z", 6);
    glutAddMenuEntry("De-Increment Z", 7);
    glutAddMenuEntry("Reset Camera", 8);
    glutAddMenuEntry("Exit", 9);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/*
 / Purpose: Function performs code for the right click menu
 */
void menu(int n) {
    
    switch (n) {
        case 0:
            glEnable(GL_LIGHTING);
            break;
            
        case 1:
            glDisable(GL_LIGHTING);
            break;
            
        case 2:
            glEnable(GL_LIGHT0);
            break;
            
        case 3:
            glDisable(GL_LIGHT0);
            break;
            
        case 4:
            glEnable(GL_LIGHT1);
            break;
        
        case 5:
            glDisable(GL_LIGHT1);
            break;
            
        case 6:
            camZ += 6;
            break;
            
        case 7:
            camZ -= 6;
            break;
            
        case 8:
            camX = 0;
            camY = 0;
            camZ = 10;
            break;
            
        case 9:
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
    
    //Ensures that camera cannot be clicked below the grass
    if (camY < 0) {
        camY = 0.5;
    }
    
    display();
}


