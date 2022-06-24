#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
GLfloat a=0,b=0;
GLfloat strip1[4][2]={{300,220},{370,210},{375,190},{310,210}};
GLfloat tail_point[3][2]={{140,18},{175,-8},{130,-20}};
void myEllipse(int x,int y,float StAngle,float EndAngle,int RX, int RY)
{
	double i;
	glBegin(GL_POLYGON);

	i=StAngle;
	while(i<=EndAngle)
	{
		glVertex2f(int((RX*cos(i)+y)+.5),int((RY*sin(i)+x)+.5));
		i=i+.001;
	}
		glEnd();
}
void update(int v){
    if(a>=200.0){
        a=-900.0;
    }
    if(b>=200.0){
        b=-800.0;
    }
    b=b+0.2;
    a=a+0.4;
    glutPostRedisplay();
    glutTimerFunc(100,update,1000);
}
void cloud1(){

    glTranslatef(a,0.0,0.0);
    myEllipse(340,250,0,360,25,50);
    //glTranslatef(a,0.0,0.0);
    myEllipse(340,275,0,360,25,50);
    //glTranslatef(a,0.0,0.0);
    myEllipse(340,300,0,360,25,50);
    glBegin(GL_POLYGON);
        glVertex2i(250,290);
        glVertex2i(250,330);
        glVertex2i(300,330);
        glVertex2i(300,290);
    glEnd();
    //glTranslatef(a,0.0,0.0);
    myEllipse(380,275,0,360,25,50);

}

void cloud2(){
    glTranslatef(b,0.0,0.0);
    myEllipse(300,150,0,360,25,50);
    //glTranslatef(a,0.0,0.0);
    myEllipse(300,175,0,360,25,50);
    //glTranslatef(a,0.0,0.0);
    myEllipse(300,200,0,360,25,50);
    glBegin(GL_POLYGON);
        glVertex2i(150,260);
        glVertex2i(150,290);
        glVertex2i(200,290);
        glVertex2i(200,260);
    glEnd();
    //glTranslatef(a,0.0,0.0);
    myEllipse(340,175,0,360,25,50);

}
void cloud3(){
    glTranslatef(b,0.0,0.0);
    myEllipse(320,100,0,360,25,50);
    //glTranslatef(a,0.0,0.0);
    myEllipse(320,125,0,360,25,50);
    //glTranslatef(a,0.0,0.0);
    myEllipse(320,150,0,360,25,50);
    glBegin(GL_POLYGON);
        glVertex2i(100,380);
        glVertex2i(100,320);
        glVertex2i(150,320);
        glVertex2i(150,280);
    glEnd();
    //glTranslatef(a,0.0,0.0);
    myEllipse(360,125,0,360,25,50);

}
void cloud5(){

    glTranslatef(a,0.0,0.0);
    myEllipse(340,50,0,360,25,50);
    //glTranslatef(a,0.0,0.0);
    myEllipse(340,75,0,360,25,50);
    //glTranslatef(a,0.0,0.0);
    myEllipse(340,100,0,360,25,50);

    //glTranslatef(a,0.0,0.0);
    myEllipse(340,75,0,360,25,50);

}
void background(){


    glColor3f(0.196078,0.6,0.8); //sky
    glBegin(GL_POLYGON);
    glVertex2i(-600,-150);
    glVertex2i(-600,600);
    glVertex2i(600,600);
    glVertex2i(600,-150);
    glEnd();
     glColor3f(0.5,1.0,0.0);
    //glBegin(GL_POLYGON);
    //glVertex2i(-600,-600);
    //glVertex2i(-600,-150);
    //glVertex2i(600,-150);
    //glVertex2i(600,-600);
    //glEnd();
    myEllipse(-850,0,0,360,900,850);

    //glColor3f(1.0,1.0,0.0);
    //glBegin(GL_TRIANGLES);
        //  glVertex2i(200,150);
      //    glVertex2i(150,150);
      //    glVertex2i(300,150);
    //glEnd();

    glColor3f(1.2,0.9,0.8);
    myEllipse(330,200,0,360,25,50);
    //glScalef(0.5,0.6,0.0);
    //glTranslatef(10.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    cloud1();
    glScalef(0.75,0.8,0.0);
    cloud2();
    cloud3();
    cloud5();
}
void display(){
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
background();
glFlush();
}
void myinit()
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glColor3f(1.0, 0.0, 0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Filling a Polygon using Scan-line Algorithm");
glutDisplayFunc(display);
myinit();
glutTimerFunc(100,update,1000);
glutMainLoop();
}
