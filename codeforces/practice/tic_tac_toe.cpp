#include<bits/stdc++.h>
using namespace std;

char a[3][3];
int main(){
    for(int i = 0; i < 9; ++i)while((a[i/3][i%3]=getchar()) == '\n');
    int x = 0, z = 0;
    for(int i = 0; i < 9; ++i)x+=a[i/3][i%3]=='X',z+=a[i/3][i%3]=='0';
    if(abs(x-z) > 1 || z > x)return printf("illegal"),0;
    int w1 = 0, w2 = 0;
    for(int i = 0; i < 3; ++i){
        if(a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] == 'X')w1++;
        if(a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] == '0')w2++;
    }
    for(int i = 0; i < 3; ++i){
        if(a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] == 'X')w1++;
        if(a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] == '0')w2++;
    }
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == 'X')w1++;
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == '0')w2++;
    if(a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] == 'X')w1++;
    if(a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] == '0')w2++;
    if(w1 && w2)return printf("illegal"),0;
    if(w2 && x != z)return printf("illegal"),0;
    if(w1 && x == z)return printf("illegal"),0;
    if(w1)return printf("the first player won"),0;
    if(w2)return printf("the second player won"),0;
    if(x+z == 9)return printf("draw"),0;
    if(x > z)return printf("second"),0;
    return printf("first"),0;
}