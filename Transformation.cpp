#include<windows.h>
#include <GL/glut.h>
#include<stdio.h>
#include <math.h>
#include<iostream>

using namespace std;
int ww = 800,wh = 500;
int N,ch,sides;
float sx,sy,rx,mythetha,rsum=0,rthetha,xc,yc,x2,y2,xnew,ynew,check=0;
double theta1,theta2;
void printpoint(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}
void drawline(float x, float y, float k, float l){
glBegin(GL_LINES);
glVertex2f(x, y);
glVertex2f(k, l);
glEnd();
glFlush();
}

void transformation1()
{
    float rthetha1=rthetha*(3.14/180);
    float r = sqrt((x2-xc)*(x2-xc) + (y2-yc)*(y2-yc));
float theta = (360.0/sides)*(3.14/180);
int i;
float m;
m = (y2-yc)/(x2-xc);
double angle = atan(m);

for(i=0;i<sides;i++)
{
     theta1 = theta*i + angle;
     theta2 = theta*(i+1) + angle;
drawline((r)*cos(theta1)+xc,(r)*sin(theta1)+yc,(r)*cos(theta2)+xc,(r)*sin(theta2)+yc);
}
for(i=0;i<sides;i++)
{
     theta1 = theta*i + angle+rthetha1;
     theta2 = theta*(i+1) + angle+rthetha1;
     if(sx == 0 && sy == 0)
drawline((r)*cos(theta1)+xc,(r)*sin(theta1)+yc,(r)*cos(theta2)+xc,(r)*sin(theta2)+yc);
else
  drawline(sx*(r*cos(theta1))+xc,sy*(r*sin(theta1))+yc,sx*(r*cos(theta2))+xc,sy*(r*sin(theta2))+yc);
}
}



void transformation()
{
float rthetha1=rthetha*(3.14/180);
float r = sqrt((x2-xc)*(x2-xc) + (y2-yc)*(y2-yc));
float theta = (360.0/sides)*(3.14/180);
int i;
float m;
m = (y2-yc)/(x2-xc);
double angle = atan(m);

xc=xc+(xnew-xc);
yc=yc+(ynew-yc);
for(i=0;i<sides;i++)
{
     theta1 = theta*i + angle+rthetha1;
     theta2 = theta*(i+1) + angle+rthetha1;
     if(sx == 0 && sy == 0)
drawline((r)*cos(theta1)+xc,(r)*sin(theta1)+yc,(r)*cos(theta2)+xc,(r)*sin(theta2)+yc);
else
  drawline(sx*(r*cos(theta1))+xc,sy*(r*sin(theta1))+yc,sx*(r*cos(theta2))+xc,sy*(r*sin(theta2))+yc);
}
}
void mouse(int button, int state, int x, int y)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
if(check==0)
{
xc = x;
yc = wh-y;
check = 1;
printpoint(xc,yc);
}
else if(check==1)
{
x2 = x;
y2 = wh-y;
if(sx == 0 && sy == 0 && rthetha == 0)
check = 2;
else
    check=0;
transformation1();
printpoint(x2,y2);
}
else if(check==2)
{
    xnew=x;
    ynew=wh-y;
    check=0;
    printpoint(xnew,ynew);
    transformation();
}
}
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void display(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(1.0,1.0,1.0);
gluOrtho2D(0.0,ww,0.0,wh);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPointSize(1);
    glBegin(GL_POINTS);
    for(int i=0; i<=ww; i++)
        glVertex2i(i,wh/2);
    for(int i=0; i<=wh; i++)
        glVertex2i(ww/2,i);
    glEnd();
glutMouseFunc(mouse);
}

int main(int argc, char** argv)
{
printf("Enter the number of sides\n");
scanf("%d",&sides);
cout<<"Enter the rotation angle";
cin>>rthetha;
cout<<"Enter scaling matrix";
cin>>sx>>sy;
glutInitWindowSize(ww,wh);
glutInitWindowPosition(100, 100);
init();
glutCreateWindow("transformation");
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

