#include<bits/stdc++.h>
using namespace std;


int main(){
    const int N = 3e5+10;
    int n,m,q,a,b,c,dia[N],h[N],p[N];
    scanf("%d%d%d",&n,&m,&q);
    iota(p,p+n+1,0);
    fill(dia,dia+n+1,1);
    fill(h,h+n+1,1);
    function<int(int)> fp = [&](int x)->int{
        if(x != p[x])p[x] = fp(p[x]);
        return p[x];
    };
    auto u = [&](int a, int b){
        a = fp(a), b = fp(b);
        if(a == b)return;
        dia[b] = max({dia[b],dia[a],h[a]/2+h[b]/2+h[a]%2+h[b]%2});
        h[b] = max(h[a]/2+h[b]/2+h[a]%2+h[b]%2,h[b]);
        p[a] = b;
    };
    while(m--){
        scanf("%d%d",&a,&b);
        u(a,b);
    }
    while(q--){
        scanf("%d",&a);
        if(a == 2){
            scanf("%d%d",&b,&c);
            u(c,b);
        }else{
            scanf("%d",&b);
            printf("%d\n",dia[fp(b)]);
        }
    }
    return 0;
}