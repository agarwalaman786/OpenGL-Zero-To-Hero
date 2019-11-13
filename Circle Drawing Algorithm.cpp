#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#define window_wide 800
#define window_height 500
float xi,yi,xf,yf,ch=0;
void drawline(float a, float b,float a1, float b1){
glVertex2f(a,b);
glVertex2f(a1,b1);
}
void circle()
{
int radius = sqrt((xf-xi)*(xf-xi)+(yf-yi)*(yf-yi));
int x = 0, y = radius;
float d = 5.0/4.0-radius;
glBegin(GL_POINTS);
while(x<=y)
{
    x=x+1;
    if(d<0)
        d=d+2*x+1;
    else
    {
        y=y-1;
        d=d+2*(x-y)+1;
    }
        glVertex2i(xi+x,yi+y);

        glVertex2i(xi+x,yi-y);
        glVertex2i(xi-x,yi+y);
        glVertex2i(xi-x,yi-y);
        glVertex2i(xi+y,yi+x);
        glVertex2i(xi+y,yi-x);
        glVertex2i(xi-y,yi+x);
        glVertex2i(xi-y,yi-x);

}
glEnd();
glFlush();
}
void myMouse(int button, int state, int x, int y)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
if(ch==0)
{
xi = x;
yi = window_height-y;
ch = 1;
glBegin(GL_POINTS);
glVertex2i(xi,yi);
glEnd();
glFlush();
}
else if(ch==1)
{
xf = x;
yf = window_height-y;
ch = 0;
circle();
}
}
}
void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0,10.0,-10.0,10.0);
}

void myDisplay(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(1.0,0.0,0.0);
gluOrtho2D(0.0,window_wide,0.0,window_height);
glClear(GL_COLOR_BUFFER_BIT);
glutMouseFunc(myMouse);
}

int main(int argc, char** argv)
{
glutInitWindowSize(window_wide,window_height);
glutInitWindowPosition(100, 100);
init();
glutCreateWindow("Midpoint Circle Algorithm");
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}
