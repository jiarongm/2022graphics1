#include <GL/glut.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�e���e���M���e��

    glColor3f(1,1,0);///�]�w�C��
    //glutSolidTeapot(0.3);///�e����
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(-1,-1);

        glColor3f(0,1,0);
        glVertex2f(+1,-1);

        glColor3f(0,0,1);
        glVertex2f(0,+1);
    glEnd();

    glutSwapBuffers();///�e�n��e�{�X��
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///���w�İ�+3D�`�ץ\��
    glutCreateWindow("��02�P���{����!");///�}��GLUT����

    glutDisplayFunc(display);///�Ψ���ܪ��{��
    glutMainLoop();///�D�n���{���j��
}
