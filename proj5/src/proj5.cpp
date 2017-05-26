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

// Lesson 6: A Simple Animation
// Author: Michael Hall
//
// This C++ code and project are provided "as is"
// without warranty of any kind. For personal use only,
// not for distribution. Copyright 2010 XoaX.
#include <GL/glut.h>

GLfloat gfPosX = 0.0;
GLfloat gfDeltaX = .01;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, .50, 1.0);
    glBegin(GL_LINES);
        glVertex3f(gfPosX, 0.25, 0.0);
//        glVertex3f(1.0 - gfPosX, 0.75,0.0);
        glVertex3f(gfPosX, gfPosX, 0.0);
        glColor3f(1.0, gfPosX, gfPosX);
    glEnd();
    glutSwapBuffers();
    gfPosX += gfDeltaX;
    if (gfPosX >= 1.0 || gfPosX <= 0.0) {
        gfDeltaX = -gfDeltaX;
    }
}

void Timer(int iUnused)
{
    glColor3f(gfPosX, 1.0, gfPosX);
   glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("XoaX.net");
    Initialize();
    glutDisplayFunc(Draw);
    Timer(0);
    glutMainLoop();
    return 0;
}
