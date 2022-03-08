#include <GL/glut.h>
#include <stdio.h>

float mouseX=0,mouseY=0;
void myteatop(float x,float y){
    glPushMatrix();///備份矩陣
    ///移動會累積，因為它會修改矩陣
        glTranslatef(x, y , 0);//x,y,z方向
        glColor3f(1,1,0);
        glutSolidTeapot(0.1);
    glPopMatrix();///還原矩陣(還原舊的位置)
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

