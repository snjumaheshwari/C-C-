#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void fun()
{
	int x,y,x2,y2;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	
	glBegin(GL_TRIANGLE_FAN);
	int x0,y0,x1,y1;
	
	cin>>x0>>y0>>x1>>y1;
	
	int dx=x1-x0;
	int dy=y1-y0;
	
	int p0=2*dy -dx;
	int i=0;
	while(i<dx-1)
	{
		if(p0<0)
		{
			x++;
			glVertex2f(x,y);
			p0=p0+2*dy;
			
		}
		else
		{
			x++;
			y++;
			glVertex2f(x,y);
			p0=p0+2*dy -2*dx;
		}
	}	
	
	glVertex2f(x2,y2);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex2f(x2,y2);
	
	glVertex2f(x2+20,y2-20);
	glVertex2f(x2-20,y2-20);
	glEnd();
	glFlush();
	
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
