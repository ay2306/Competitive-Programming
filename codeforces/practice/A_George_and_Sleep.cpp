#include<bits/stdc++.h>
using namespace std;

int main(){
    int mod = 60*24;
    int h1,m1,h2,m2;
    scanf("%d:%d",&h1,&m1);   
    scanf("%d:%d",&h2,&m2);
    int wake = h1*60 + m1;
    int TIME = h2*60 + m2;
    int slept = (wake-TIME+mod)%mod;
    printf("%02d:%02d",slept/60,slept%60);
    return 0;
}