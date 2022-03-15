#include <GL/glut.h>///使用GLUT的外掛
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫之前先清除畫面
    glPushMatrix();///備份矩陣
        glRotatef(90,0,0,1);
        glutSolidTeapot(0.3);///畫茶壺
    glPopMatrix();///還原矩陣

    glutSwapBuffers();///畫好後呈現出來
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("第02周的程式喔!");///開啟GLUT視窗

    glutDisplayFunc(display);///用來顯示的程式
    glutMainLoop();///主要的程式迴圈
}
