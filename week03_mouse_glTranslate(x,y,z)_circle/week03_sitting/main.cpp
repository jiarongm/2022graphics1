#include <GL/glut.h>
#include <stdio.h>

float mouseX=0,mouseY=0;
void myteatop(float x,float y){
    glPushMatrix();///�ƥ��x�}
    ///���ʷ|�ֿn�A�]�����|�ק�x�}
        glTranslatef(x, y , 0);//x,y,z��V
        glColor3f(1,1,0);
        glutSolidTeapot(0.1);
    glPopMatrix();///�٭�x�}(�٭��ª���m)
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    myteatop((mouseX-150)/150.0,-(mouseY-150)/150.0);
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y){
    printf("button= %d state=%d x=%d y=%d\n",button,state,x,y);
    mouseX=x;
    mouseY=y;
}
int main(int argc,char**argv){
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03_mouse");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}

