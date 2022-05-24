//Declaration



#include<windows.h>
#include <GL/glut.h>
#define RED 2
#define GREEN 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define YELLOW 7
#define BLACK 8
#define ERASER 9

//Global variable

int ScreenHeight=600, brushSize=5;
float red=1.0, green=0.0, blue=1.0;

//<<<<<<<My Initial Window>>>>>>
void myInti(void)
{
    glClearColor(0.0,0.0,0.0,0.0); //set background color to white
    glColor3f(red, green, blue);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,600);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void myMovedMouse(int mousex, int mousey)
{
    glColor3f(red,green,blue);
    GLint x=mousex;
    GLint y=ScreenHeight-mousey;
    glRecti(x,y,x+brushSize,y+brushSize);
    glRecti(x,y,x+brushSize,y+brushSize);
    glFlush();
}

void myKeyboard (unsigned char thekey, int mouseX, int mouseY)
{
    switch (thekey)
    {
    case '+':
        brushSize++; // increase the line width.
        break;
    case '-':
        if(brushSize>1.0)
            brushSize--; // Decrease the line width.
        break;
    case 'c':
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        break;
    case 'e':
        exit(-1);
    default:
        break;
    }
}


void processMenuEvents(int option)
{
    switch(option)
    {
        case RED: red=1.0; green=0.0; blue=0.0; break;
        case GREEN: red=0.0; green=1.0; blue=0.0; break;
        case BLUE: red=0.0; green=0.0; blue=1.0; break;
        case MAGENTA: red=1.0; green=0.0; blue=1.0; break;
        case CYAN: red=0.0; green=1.0; blue=1.0; break;
        case YELLOW: red=1.0; green=1.0; blue=0.0; break;
        case BLACK: red=0.0; green=0.0; blue=0.0; break;
        case ERASER: red=1.0; green=1.0; blue=1.0; break;
    }
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize (800,600);
    glutInitWindowPosition (200,50);
    glutCreateWindow("My Painting Canvas");
    glutDisplayFunc(myDisplay);
    glutMotionFunc(myMovedMouse);
    glutKeyboardFunc(myKeyboard);
    glutCreateMenu(processMenuEvents);
    glutAddMenuEntry ("RED",RED);
    glutAddMenuEntry ("BLUE",BLUE);
    glutAddMenuEntry ("GREEN",GREEN);
    glutAddMenuEntry ("CYAN",CYAN);
    glutAddMenuEntry ("MAGENTA",MAGENTA);
    glutAddMenuEntry ("YELLOW",YELLOW);
    glutAddMenuEntry ("BLACK",BLACK);
    glutAddMenuEntry ("ERASER",ERASER);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    myInti();
    glutMainLoop();
}

