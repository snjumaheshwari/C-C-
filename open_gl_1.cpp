#include<GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

void init()
{
	glClearColor(1.0,0.0,0.0,1.0);
}

void circle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	
	// draw 

	int xc,yc,r;
	//cin>>xc>>yc>>r;
	xc=0;
	yc=0;
	r=50;
	
	int x=xc;
	int y=yc+r;
	
	while(x<=xc+r )
	{
		x++;
		y=yc+ sqrt(r*r - (x-xc)*(x-xc));
		glVertex2f(round(x),round(y));
	}
	glFlush();
	
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	
	// draw 
	
	glFlush();
	
}
/*
void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	
	
}*/
int main(int argc , char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	
	glutInitWindowPosition(200,100);
	glutInitWindowSize(500,500);
	
	glutCreateWindow("Window 1");
	glutDisplayFunc(circle);
	init();
	
	glutMainLoop();
		
	return 0;
}
