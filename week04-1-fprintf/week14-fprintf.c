#include <stdio.h>
int main(){
///檔案指標fout     開啟檔案(檔名,write模式)
    FILE*fout=fopen("file.text","w+");
    printf(     "Helloe World\n");
    fprintf(fout,"Hellow World\n");
    fclose(fout);
}
