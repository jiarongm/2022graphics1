#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0;///茶壺初始位置為正中央(150,150)
int oldx=0,oldy=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0,-(y-150)/150.0,z);///位置
        glScalef(scale,scale,scale);///縮放大小
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mousex,int mousey)
{
}
void mouse(int button,int state,int mousex,int mousey)
{///修正瞬間移動,讓茶壺最後的位置為滑鼠之前結束的位置
    oldx=mousex;
    oldy=mousey;
}
void motion(int mousex,int mousey)
{
    if((mousex-oldx)>0)scale*=1.01;
    else scale*=0.99;
    /*x+=(mousex-oldx);
    y+=(mousey-oldy);*/
    oldx=mousex;
    oldy=mousey;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
