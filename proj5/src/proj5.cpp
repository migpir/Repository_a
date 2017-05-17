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

int i;
struct Cube
{
	int all;
	float x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4,xOff,yOff,zOff;
};

Cube C[6];

void init()
{
	C[0].x1 = -0.2; C[0].y1 = -0.2; C[0].z1=1.0; //front
	C[0].x2 = -0.2; C[0].y2 =  0.2; C[0].z2=1.0;
	C[0].x3 = 0.2;  C[0].y3=  0.2;  C[0].z3=1.0;
	C[0].x4 = 0.2;  C[0].y4 = -0.2; C[0].z4=1.0;
	C[0].x4 = 0.2;  C[0].y4 = -0.2; C[0].z4=1.0;
	C[0].xOff = 0.0;  C[0].yOff = 0.0; C[0].zOff = 0.0;

	C[1].x1 = -0.2; C[1].y1 = -0.2; C[1].z1=1.5;
	C[1].x2 = -0.2; C[1].y2 =  0.2; C[1].z2=1.5;
	C[1].x3 =  0.2; C[1].y3 =  0.2; C[1].z3=1.5;
	C[1].x4 =  0.2; C[1].y4 = -0.2; C[1].z4=1.5;
    C[0].all = 2;



}

void drawFaces()
{
glBegin(GL_POLYGON);
glVertex2f(-0.2,-0.2);
glVertex2f(-0.2,0.2);
glVertex2f(0.2,0.2);
glVertex2f(0.2,-0.2);
glEnd();


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

    drawFaces();

    glFlush();
    glutSwapBuffers();


}

void move(int st, float v)
{
	for (i=0;i<C[0].all;i++)
	{
		if(st==1){C[i].x1+=v;C[i].x2+=v;C[i].x3+=v;C[i].x4+=v;}
		if(st==2){C[i].y1+=v;C[i].y2+=v;C[i].y3+=v;C[i].y4+=v;}
	}

     if(st==1){C[0].xOff+=v;}
     if(st==2){C[0].yOff+=v;}
     if(st==3){C[0].zOff+=v;}
}


void depth()
{
  for(i=0;i<C[0].all;i++)
  {
      C[i].x1+=C[0].xOff;C[i].x2+=C[0].xOff;C[i].x3+=C[0].xOff;C[i].x4+=C[0].xOff;
      C[i].y1+=C[0].xOff;C[i].y2+=C[0].xOff;C[i].y3+=C[0].xOff;C[i].y4+=C[0].xOff;
      C[i].z1+=C[0].xOff;C[i].z2+=C[0].xOff;C[i].z3+=C[0].xOff;C[i].z4+=C[0].xOff;
	  C[i].x1/=C[i].z1; C[i].y1/=C[i].z1;
	  C[i].x2/=C[i].z2; C[i].y2/=C[i].z2;
	  C[i].x3/=C[i].z3; C[i].y3/=C[i].z3;
	  C[i].x4/=C[i].z4; C[i].y4/=C[i].z4;
  }
}

void keyboard(unsigned char key, int x, int y)
{
	if(key=='a') {(move(1,-0.1));}   // move left
	if(key=='d') {(move(1,0.1));}    // move right
	if(key=='e') {(move(2,-0.1));}   // move up
	if(key=='z') {(move(2,0.1));}    // move down
	if(key=='f') {(move(3,0.1));}    // move forwar
	if(key=='w') {(move(3,-0.1));}   // move back
	if(key>0) {init();depth();}      // reset

    glutPostRedisplay();


}


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("My First OpenGL Program");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
	glClearColor(0.3,0.3,0.3,5.0);
	glutMainLoop();
	return 0;
}
