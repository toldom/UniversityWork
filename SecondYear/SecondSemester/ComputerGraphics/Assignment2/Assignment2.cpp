/*                                              /
/   03-06-352  -  Intro to Computer Graphics    /
/   Assignment 2 - Truck Program                /
/   Marcus Toldo - 104623006                    /
/   Wednesday, February 14, 2018                /
/                                              */

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <stdlib.h>

void setup();   // initialization of the program
void display(); // drawing method
void draw();    // draw the object
void CreateRGB();
void DrawTruck(int, int);
void DrawTire(int, int);
void DrawRoad(int);
void OnMouseClick(int, int, int, int);
void Driving(int);
void Menu(int);
void CreateMyMenu();

//Global Variables
//General
int r, g, b, move = 4.0f, position = 7, amGoingLeft = 0;
int windowW = 1280, windowH = 720;
bool isClicked = false;

//Truck
int truckOrigin[2] = {0, 60}, truckOffsetX = 400, truckOffsetY = 150;
int cabinOffsetX = 90, cabinOffsetY = 150;

int main(int argc, char *argv[]){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(windowW, windowH);
    glutCreateWindow("toldom_Assignment2");
    glutDisplayFunc(display);
    
    CreateMyMenu();
    
    setup();
    glutMouseFunc(OnMouseClick);
    glutTimerFunc(30, Driving, -1);
    glutMainLoop();
    
    return 0;
    
}

//OpenGL setup
void setup(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, windowW, 0, windowH);
}

//OpenGL draw function
void draw(){
    
    if (move < 0) {
        amGoingLeft = true;
    } else {
        amGoingLeft = false;
    }

    //Resetting Truckto left side when it rolls off the right
    if (position > 1280 && !amGoingLeft) {
        glTranslatef(-1880, 0, 0);
        position = -600;
    } else if (position < -600 && amGoingLeft) {
        glTranslatef(1280+600, 0,0);
        position = 1280+600;
    }
    
    //Ambiently moving the truck
    glTranslatef(move, 0.0f, 0.0f);
    
    DrawRoad(1280);
    DrawTruck(truckOrigin[0], truckOrigin[1]);
}

//Draws the truck at a given position
void DrawTruck(int posX, int posY) {
    
    glColor3f(0, 0, 0);
    
    //Drawing truck body
    glBegin(GL_POLYGON);
    glVertex2f(posX, posY);
    glVertex2f(posX+truckOffsetX, posY);
    glVertex2f(posX+truckOffsetX, posY+truckOffsetY);
    glVertex2f(posX, posY+truckOffsetY);
    glEnd();
    
    //Drawing Truck Cabin
    glBegin(GL_POLYGON);
    glVertex2f(posX+truckOffsetX+20, posY);
    glVertex2f(posX+truckOffsetX+20+cabinOffsetX, posY);
    glVertex2f(posX+truckOffsetX+20+cabinOffsetX, posY+cabinOffsetY);
    glVertex2f(posX+truckOffsetX+20, posY+cabinOffsetY);
    glEnd();
    
    //Drawing body link
    glBegin(GL_POLYGON);
    glVertex2f(posX+truckOffsetX, posY+15);
    glVertex2f(posX+truckOffsetX+20, posY+15);
    glVertex2f(posX+truckOffsetX+20, posY+15+10);
    glVertex2f(posX+truckOffsetX, posY+15+10);
    glEnd();
    
    //Change color to Light Grey
    glColor3f(0.85, 0.85, 0.85);
    
    //Drawing Window
    glBegin(GL_POLYGON);
    glVertex2f(posX+truckOffsetX+40, posY+truckOffsetY-10);
    glVertex2f(posX+truckOffsetX+100, posY+truckOffsetY-10);
    glVertex2f(posX+truckOffsetX+100, posY+truckOffsetY-60);
    glEnd();
    
    //Drawing Door
    glBegin(GL_POLYGON);
    glVertex2f(posX+truckOffsetX+12+20, posY+20);
    glVertex2f(posX+truckOffsetX+12+50, posY+20);
    glVertex2f(posX+truckOffsetX+12+50, posY+20+70);
    glVertex2f(posX+truckOffsetX+12+20, posY+20+70);
    glEnd();
    
    //Change color to darker grey
    glColor3f(0.3, 0.3, 0.3);
    //Tire
    DrawTire(truckOrigin[0]+40, truckOrigin[1]-40);
    DrawTire(truckOrigin[0]+335, truckOrigin[1]-40);
    DrawTire(truckOrigin[0]+450, truckOrigin[1]-40);
    
}

//Draws a tire at a given position
void DrawTire(int posX, int posY) {
    
    //Tire
    glBegin(GL_POLYGON);
    glVertex2f(posX, posY);
    glVertex2f(posX+30, posY);
    glVertex2f(posX+50, posY+30);
    glVertex2f(posX+30, posY+60);
    glVertex2f(posX, posY+60);
    glVertex2f(posX-20, posY+30);
    glEnd();
    
}

//Draws the road
void DrawRoad(int origin) {
    
    //Set Colour to black
    glColor3f(0.0, 0.0, 0.0);
    
    //Drawing Road
    glBegin(GL_POLYGON);
    glVertex2f(-origin, 40);
    glVertex2f(origin*2, 40);
    glVertex2f(origin*2, 0);
    glVertex2f(-origin, 0);
    glEnd();
    
    //Set colour to white
    glColor3f(1, 1, 1);
    
    //Draw center line
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    
    glVertex2f(-1280, 20);
    glVertex2f(1280*2, 20);
    glEnd();
}

//Drive fucntion
void Driving(int data) {
    if (!isClicked) {
        glutTimerFunc(30, Driving, -1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        position+=move;
        glutPostRedisplay();
    } else {
        glutTimerFunc(30, Driving, -1);
    }
    
    
}

//To be executed on mouse click
void OnMouseClick(int button, int state, int x, int y) {
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (!isClicked) {
            isClicked = true;
        } else {
            isClicked = false;
        }
    }
    
}

//Setup for the menu
void Menu(int num) {
    
    switch (num) {
        case 1:
            move += 3;
            break;
            
        case 2:
            move -= 3;
            break;
            
        case 3:
            move *= -1;
            break;
            
        case 4:
            exit(0);
            break;
            
        default:
            break;
    }
    
}

//Creates the menu and attaches it to the right mouse click
void CreateMyMenu() {
    
    glutCreateMenu(Menu);
    glutAddMenuEntry("Speed Up", 1);
    glutAddMenuEntry("Slow Down", 2);
    glutAddMenuEntry("Reverse", 3);
    glutAddMenuEntry("Quit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
}

//Display Function
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(r/255., g/255., b/255.);
    
    draw();
    
    glFlush();
}

//Takes RGB color info from the user
void CreateRGB() {
    
    std::cout << "Enter the R value (0 <--> 255): ";
    std::cin >> r;
    
    std::cout << "Enter the G value (0 <--> 255): ";
    std::cin >> g;
    
    std::cout << "Enter the B value (0 <--> 255): ";
    std::cin >> b;
    
}
