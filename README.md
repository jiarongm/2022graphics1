# 2022graphics1
##
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
