#include <GL/glut.h>///使用GLUT的外掛
float angle=0,oldx=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫之前先清除畫面
    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);///畫茶壺
    glPopMatrix();///還原矩陣

    glutSwapBuffers();///畫好後呈現出來
}
void motion(int x,int y){
    angle+=(x-oldx);
    oldx=x;
    display();///變更後再重畫 畫面
}
void mouse(int button,int state,int x,int y){
    oldx=x;
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("第04周的程式喔!");///開啟GLUT視窗

    glutDisplayFunc(display);///用來顯示的程式
    glutMotionFunc(motion);///mouse motion移動
    glutMouseFunc(mouse);///03周教的滑鼠控制

    glutMainLoop();///主要的程式迴圈
}
