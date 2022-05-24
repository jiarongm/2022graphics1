#include <GL/glut.h>
float angle[20],oldX=0;
int angleID=0;
void keyboard(unsigned char key,int x,int y){
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}
void mouse(int button,int state,int  x,int y){///當按下滑鼠時
    oldX=x;
}
void motion(int x,int y){
    angle[angleID]+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///請GLUT重畫 畫面
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);///身體 四邊形

    glPushMatrix();
        glTranslatef(0.3,0.4,0);///(3)把手臂掛回身體
        glRotatef(angle[0],0,0,1);///(2)旋轉45度
        glTranslatef(-0.3,-0.4,0);///(1)移動旋轉中心至(0,0)
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///(3)把手臂掛回身體
            glRotatef(angle[1],0,0,1);///(2)旋轉45度
            glTranslatef(-0.7,-0.4,0);///(1)移動旋轉中心至(0,0)
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);///下手臂
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///(3)把手臂掛回身體
        glRotatef(angle[2],0,0,1);///(2)旋轉45度
        glTranslatef(+0.3,-0.4,0);///(1)移動旋轉中心至(0,0)
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);///上手臂

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///(3)把手臂掛回身體
            glRotatef(angle[3],0,0,1);///(2)旋轉45度
            glTranslatef(+0.7,-0.4,0);///(1)移動旋轉中心至(0,0)
            glColor3f(0,1,0);
            glRectf(-0.7,0.5,-1.0,0.3);///下手臂
        glPopMatrix();

    glPopMatrix();


    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);///按下滑鼠
    glutMotionFunc(motion);///長按滑鼠移動
    glutDisplayFunc(display);
    glutMainLoop();
}
