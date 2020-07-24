//https://codeforces.com/contest/1288/problem/A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,d,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);
        int x = sqrt(d),pos=0;
        for(int i = max(0,x-100); i <= x+100; ++i){
            pos+=((d+i)/(i+1) + i) <= n;
        }
        pos > 0 ? printf("YES\n"):printf("NO\n");
    }
    return 0;
}