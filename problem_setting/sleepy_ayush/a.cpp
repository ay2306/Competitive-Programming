#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int h1,h2,m1,m2;
        scanf("%d:%d",&h1,&m1);
        scanf("%d:%d",&h2,&m2);
        int res = (h2*60+m2 - h1*60-m1);
        if(res < 0)res+=24*60;
        printf("%d hours %d minutes\n",res/60,res%60);
    }
    return 0;
}