#include <stdio.h>
int main(){
///�ɮ׫���fout     �}���ɮ�(�ɦW,write�Ҧ�)
    FILE*fout=fopen("file.text","w+");
    printf(     "Helloe World\n");
    fprintf(fout,"Hellow World\n");
    fclose(fout);
}
