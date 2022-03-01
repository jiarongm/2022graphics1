# 2022graphics1
## week02
Week02_點、線、面、色彩

1.下載範例https://jsyeh.org/3dcg10/


windows.zip=7.zip=解壓縮至windows/

data.zip =解壓縮後把資料夾放進windows裡
glut32.dll=複製=貼到windows資料夾裡


開啟Shapes.exe看範例



在左邊點擊滑鼠右鍵:大頂點、更改顏色
在右邊點擊滑鼠右鍵:point(點)....polygon(面)

2.跑上周的程式
下載git fot windows >git bash>cd desktop>git clone 你的github網址
下載freeglut>解壓縮至桌面開啟freeglut資料夾>bin>複製 libfreeglut.a 原地貼上後再改名為 libglut32.a
開啟codeblocks>OPEN>桌面>week01_GLUT>跑

3.開始寫GLUT程式
codeblocks>New file>project>GLUT>go > next > projet title:命名專案名稱為week02_color  > 位置設為桌面>next  > close > 是 > 點擊「...」 >  選取剛才的freeglut資料夾
>>>>>程式碼全部刪掉，自己寫:
```
#include <GL/glut.h>///使用GLUT的外掛
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫之前先清除畫面

    glColor3f(1,1,0);///設定顏色
    glutSolidTeapot(0.3);///畫茶壺

    glutSwapBuffers();///畫好後呈現出來
}
int main(int argc,char** argv){
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("第02周的程式喔!");///開啟GLUT視窗

    glutDisplayFunc(display);///用來顯示的程式
    glutMainLoop();///主要的程式迴圈
}
```

4.模仿範例
```
//glutSolidTeapot(0.3);///畫茶壺
    glBegin(GL_POLYGON);     //開始 polygon(多邊形)
        glColor3f(1,0,0);    // 一組
        glVertex2f(-1,-1);     //vertetx(頂點)   2f(兩個浮點數)

        glColor3f(0,1,0);
        glVertex2f(+1,-1);

        glColor3f(0,0,1);
        glVertex2f(0,+1);

    glEnd();    //結束(停止在這裡)
```





## week01
1.用Codeblocks 17.12 做一個OpenGL的專案

    codeblocks > file > new > Project >





    OpenGL project > Go

    next > 點擊「...」 >  桌面 >  Next  > Next > 完成 !

    build & run >> 看到旋轉的彩色三角形





2.用Codeblocks 17.12 做一個GLUT的專案
    Moodle下載freeglut壓縮檔 > 解壓縮至桌面 >點擊freeglut 資料夾 > lib 

    




    > 複製 libfreeglut.a 原地貼上後再改名為 libglut32.a

    > codeblocks > file > new > Project > GLUT專案



    > go > next > projet title:命名專案名稱為week01_GLUT  > 位置設為桌面 


> next  > close > 是 > 點擊「...」 >  選取剛才的freeglut資料夾 → finish
>執行codeblocks

>看到立體圖形



>使用+ -號改變圖型




3.利用Git指令上傳/備份
   登入github > 建立2022graphics 的 repo倉庫 >
   設定:公開Public /README.md /Add .gitignore 設定 C++
    > 安裝 Git for Windows > 開啟 Git Bash
    > cd desktop 進入桌面
    > git clone https://你的倉庫網址
    > 查看 桌面,多了 2022graphics 目錄
    > 把今天的程式 複製到 剛剛目錄

把修改的資料, 推送到雲端

    >  cd 2022graphics 進入你的倉庫
    >  git status 看你的狀況(紅的,多了目錄)
    >  git add . 把檔案加進帳冊
    >  git status 再看一次(綠的)
  

```

git config --global user.email "你的email"
git config --global user.name "你的名"
git commit -m "上傳第1週"

```

git push 推送到雲端, BUT要登入
