#include <Gl/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float x=150,y=150,z=0,scale=1.0,angle=0.0;///������l��m��������(150,150)
int oldx=0,oldy=0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glTranslatef( (x-150)/150.0,-(y-150)/150.0,z);///��m
        glScalef(scale,scale,scale);///�Y��j�p
        glRotatef(angle,0,1,0);///����>>>��Y�b(0,1,0)
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void mouse(int button,int state,int mousex,int mousey)
{///�ץ���������,�������̫᪺��m���ƹ����e��������m
    oldx=mousex;
    oldy=mousey;
}
void motion(int mousex,int mousey)
{
    angle+=(mousex-oldx);///����
    if((mousex-oldx)>0)scale*=1.01;///�Y��
    else scale*=0.99;
    /*x+=(mousex-oldx);
    y+=(mousey-oldy);*/
    oldx=mousex;
    oldy=mousey;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06_light");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glEnable(GL_DEPTH_TEST);///�}�Ҳ`�ץ\��(3D)
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
