#include <Gl/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float x=150,y=150,z=0,scale=1.0,angle=0.0;///茶壺初始位置為正中央(150,150)
int oldx=0,oldy=0,now=1;

void display()
{
    glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef( (x-150)/150.0,-(y-150)/150.0,z);///位置
        glScalef(scale,scale,scale);///縮放大小
        glRotatef(angle,0,1,0);///旋轉>>>對Y軸(0,1,0)
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mousex,int mousey)
{
    if(key=='1'||key=='w'||key=='W')now=1;
    if(key=='2'||key=='e'||key=='E')now=2;
    if(key=='3'||key=='r'||key=='R')now=3;
}
void mouse(int button,int state,int mousex,int mousey)
{///修正瞬間移動,讓茶壺最後的位置為滑鼠之前結束的位置
    oldx=mousex;
    oldy=mousey;
}
void motion(int mousex,int mousey)
{
    if (now==1){///移動
        x+=(mousex-oldx);
        y+=(mousey-oldy);
    }else if(now==2){
        angle+=(mousex-oldx);///旋轉
    }else if(now==3){///縮放
        if((mousex-oldx)>0)scale*=1.005;
        if((mousex-oldx)<0)scale*=0.999;
    }
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
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glEnable(GL_DEPTH_TEST);///開啟深度功能(3D)
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
