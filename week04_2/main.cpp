#include <GL/glut.h>///�ϥ�GLUT���~��
float angle=0,oldx=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�e���e���M���e��
    glPushMatrix();///�ƥ��x�}
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);///�e����
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();///�e�n��e�{�X��
}
void motion(int x,int y){
    angle+=(x-oldx);
    oldx=x;
    display();///�ܧ��A���e �e��
}
void mouse(int button,int state,int x,int y){
    oldx=x;
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///���w�İ�+3D�`�ץ\��
    glutCreateWindow("��04�P���{����!");///�}��GLUT����

    glutDisplayFunc(display);///�Ψ���ܪ��{��
    glutMotionFunc(motion);///mouse motion����
    glutMouseFunc(mouse);///03�P�Ъ��ƹ�����

    glutMainLoop();///�D�n���{���j��
}
