#include <GL/glut.h>
void myteatop(float x,float y){
    glPushMatrix();///備份矩陣
    ///移動會累積，因為它會修改矩陣
        glTranslatef(x, y , 0);//x,y,z方向
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣(還原舊的位置)
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    /*glPushMatrix();///備份矩陣
    ///移動會累積，因為它會修改矩陣
        glTranslatef(0.5, 0.5 , 0);//x,y,z方向
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣(還原舊的位置)
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

