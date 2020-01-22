#include<stdio.h>

int main(){
    FILE *fin = fopen("test.in","r");
    FILE *fout = fopen("test.out","w");
    int x,y;
    fscanf(fin,"%d %d",&x,&y);
    fprintf(fout,"%d",x+y);
    return 0;
}