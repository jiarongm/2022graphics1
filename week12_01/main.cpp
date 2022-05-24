#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///茶壺(當底)

    glPushMatrix();
        glTranslatef(0.2,0,0);///step3.(旋轉後)掛到右邊
        glRotatef(angle,0,0,1);///step2.旋轉
        glTranslatef(0.2,0,0);///step1.把旋轉中心右移(放到世界中心)
        glColor3f(1,0,0);///紅色
        glutSolidTeapot(0.2);///小茶壺
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12 TRT");

    glutDisplayFunc(display);
    glutMainLoop();
}
