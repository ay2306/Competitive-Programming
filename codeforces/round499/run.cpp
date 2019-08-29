#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    FILE *fp, *f;
    fp = fopen("code1.cpp","r");
    f = fopen("code11.cpp","w");
    while(1){
        char c = char(fgetc(fp));
        if(feof(fp))break;;
        // cout << c;
        if(c!=' ')fputc(c,f);
    }
    fclose(fp);fclose(f);
    return 0;
}