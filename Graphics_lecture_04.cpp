#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void fun()
{

}

int main()
{
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640,640);
	glutCreateWindow("openGL");
	glutDisplayFunc(fun);
	gluOrtho2D(0,640,0,640);
	glClearColor(1,1,1,1);
	glutMainLoop();
	return 0;
	
	
}
