#include <GL/glut.h>
void myteatop(float x,float y){
    glPushMatrix();///�ƥ��x�}
    ///���ʷ|�ֿn�A�]�����|�ק�x�}
        glTranslatef(x, y , 0);//x,y,z��V
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}(�٭��ª���m)
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    /*glPushMatrix();///�ƥ��x�}
    ///���ʷ|�ֿn�A�]�����|�ק�x�}
        glTranslatef(0.5, 0.5 , 0);//x,y,z��V
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}(�٭��ª���m)
    */
    myteatop(0.5,0.5);
    myteatop(-0.5,0.5);
    myteatop(0.5,-0.5);
    myteatop(-0.5,-0.5);
    glutSwapBuffers();
}
int main(int argc,char**argv){
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03_translate");

    glutDisplayFunc(display);
    glutMainLoop();
}

