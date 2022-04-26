#include <GL/glut.h>///�ϥ�GLUT���~��
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric *sphere=NULL;///���СA����G�����u
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�e���e���M���e��

    glPushMatrix();
        glRotatef(90,1,0,0);///��L�ॿ
        gluQuadricTexture(sphere,1);///�]�w�n�K��
        gluQuadricTexture(sphere,1);///�]�w�n�K��
        gluSphere(sphere,1,30,30);///�e��y
    glPopMatrix();

    glutSwapBuffers();///�e�n��e�{�X��
    angle+=1;
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///���w�İ�+3D�`�ץ\��
    glutCreateWindow("��10�P���{����!");///�}��GLUT����

    glEnable(GL_DEPTH_TEST);///�}��3D�`�״��� �~��3D�ĪG
    glutIdleFunc(display);///����idle�I�sdisplay()
    glutDisplayFunc(display);///�Ψ���ܪ��{��
    myTexture("grapth1.png");
    sphere=gluNewQuadric();///�ǳƤG�����u
    glutMainLoop();///�D�n���{���j��
}
