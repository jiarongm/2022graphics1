#include <GL/glut.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫之前先清除畫面

    glColor3f(1,1,0);///設定顏色
    //glutSolidTeapot(0.3);///畫茶壺
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(-1,-1);

        glColor3f(0,1,0);
        glVertex2f(+1,-1);

        glColor3f(0,0,1);
        glVertex2f(0,+1);
    glEnd();

    glutSwapBuffers();///畫好後呈現出來
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("第02周的程式喔!");///開啟GLUT視窗

    glutDisplayFunc(display);///用來顯示的程式
    glutMainLoop();///主要的程式迴圈
}
