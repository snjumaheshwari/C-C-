#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void fun()
{
	float x1,x2,y1,y2,dx,dy,x,y,m,absm;
	x2=140;
	y2=330;
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;
	absm=abs(m);


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_POINTS);

	// -- case 1--
	printf("%f %f",m,absm);

	if(absm>=1 && dx>0 && dy>0)
	{
		while(y<y2)
		{	
			glVertex2f(round(x),round(y));
			y++;
			x+=1/m;
		}
	}
	
	// -- case 2 --
	if(m>0 && m<1 && dx>0 && dy>0)
	{
		
	}

}
int main()
{
	
	
	fun();	
}



