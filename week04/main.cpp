#include <GL/glut.h>///�ϥ�GLUT���~��
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�e���e���M���e��
    glPushMatrix();///�ƥ��x�}
        glRotatef(90,0,0,1);
        glutSolidTeapot(0.3);///�e����
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();///�e�n��e�{�X��
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///���w�İ�+3D�`�ץ\��
    glutCreateWindow("��02�P���{����!");///�}��GLUT����

    glutDisplayFunc(display);///�Ψ���ܪ��{��
    glutMainLoop();///�D�n���{���j��
}
