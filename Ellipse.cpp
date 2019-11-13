#include<windows.h>
#include <GL/glut.h>
#include <math.h>
int ww = 800,wh = 500;

int xc,yc,x2,y2,x3,y3,check=0;

void printpoint(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}

void midpointEllipse()
{
int rx = sqrt((x2-xc)*(x2-xc) + (y2-yc)*(y2-yc));
int ry = sqrt((x3-xc)*(x3-xc) + (y3-yc)*(y3-yc));
int dp;
int x = 0;
int y = ry;
int dx = 2*ry*ry*x;
int dy = 2*rx*rx*y;
printpoint(xc+x,yc+y);
printpoint(xc-x,yc+y);
printpoint(xc+x,yc-y);
printpoint(xc-x,yc-y);
dp =ry*ry-(rx*rx*ry)+(0.25)*rx*rx+0.5;
while(dx<dy)
{
x++;
dx=dx+2*ry*ry;
if(dp < 0)
{
dp=dp+2*ry*ry+dx;
}
else
{
y--;
dy=dy-2*rx*rx;
dp=dp+2*ry*ry+dx-dy;
}
printpoint(xc+x,yc+y);
printpoint(xc-x,yc+y);
printpoint(xc+x,yc-y);
printpoint(xc-x,yc-y);
}


dp = (ry*ry*(x + 0.5)*(x+0.5)+rx*rx*(y - 1)*(y - 1)-rx*rx*ry*ry)+0.5;
while(y > 0){
y--;
dy=dy-2*rx*rx;
if(dp > 0)
{
dp=dp+rx*rx-dy;
}
else
{
x++;
dx=dx+2*ry*ry;
dp=dp+rx*rx-dy+dx;
}
printpoint(xc+x,yc+y);
printpoint(xc-x,yc+y);
printpoint(xc+x,yc-y);
printpoint(xc-x,yc-y);
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
check = 2;
}
else if(check==2)
{
x3 = x;
y3 = wh-y;
check = 0;
midpointEllipse();
}
}
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}
void display(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0,0.0,0.0);
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
glutInitWindowSize(ww,wh);
glutInitWindowPosition(100, 100);
init();
glutCreateWindow("Midpoint Ellipse Algorithm");
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
