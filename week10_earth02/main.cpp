#include <GL/glut.h>///使用GLUT的外掛
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric *sphere=NULL;///指標，指到二次曲線
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫之前先清除畫面

    glPushMatrix();
        glRotatef(90,1,0,0);///把他轉正
        gluQuadricTexture(sphere,1);///設定好貼圖
        gluQuadricTexture(sphere,1);///設定好貼圖
        gluSphere(sphere,1,30,30);///畫圓球
    glPopMatrix();

    glutSwapBuffers();///畫好後呈現出來
    angle+=1;
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("第10周的程式喔!");///開啟GLUT視窗

    glEnable(GL_DEPTH_TEST);///開啟3D深度測試 才有3D效果
    glutIdleFunc(display);///有空idle呼叫display()
    glutDisplayFunc(display);///用來顯示的程式
    myTexture("grapth1.png");
    sphere=gluNewQuadric();///準備二次曲線
    glutMainLoop();///主要的程式迴圈
}
