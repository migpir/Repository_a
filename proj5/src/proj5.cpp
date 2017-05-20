//============================================================================
// Name        : proj5.cpp
// Author      : Miguel H. Peralta
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//
// The installation of the 64 bit freeglut dll MUST be placed inside the
// c:\windows\System32!  Why?  because MicroSoft stores the 64 bit DLLs there not
// in c:\windows\SysWOW64  which is where any SANE person would expect.
//============================================================================

#include <GL/glut.h>
#include <iostream>
#include <string>
#define WIDTH 800
#define HEIGHT 600


void renderScene(void)
{

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glClearColor(1.0, 0.0, 0.0, 1.0);//clear red

    glutSwapBuffers();
    glutSwapBuffers();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(500, 500);
glutInitWindowSize(800, 600);
glutCreateWindow("OpenGL First Window");

glEnable(GL_DEPTH_TEST);

// register callbacks
glutDisplayFunc(renderScene);

glutMainLoop();

return 0;
}
