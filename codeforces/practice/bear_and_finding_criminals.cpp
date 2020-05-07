//https://codeforces.com/contest/680/problem/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[200],n,x,ans=0;
    scanf("%d%d",&n,&x);
    for(int i = 1; i <= n; ++i)scanf("%d",a+i);
    for(int l = 1; l <= n; ++l){
        int c = 0, cr = 0;
        if(x+l <= n)c++,cr+=a[x+l];
        if(x-l > 0)c++,cr+=a[x-l];
        if(c == cr)ans+=c;
    }
    return printf("%d\n",ans+a[x]),0;
}