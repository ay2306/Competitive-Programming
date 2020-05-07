#include<bits/stdc++.h>
const int N = 1e4+10;
long long f[N],g[N],pfg[N],pgg[N],n,p;

long long G(int x){
    if(x == 1)return 1;
    if(g[x] != -1)return g[x];
    g[x] = 1;
    for(int i = 1; i < x; ++i){
        g[x] = (g[x] + 2*G(i)%p)%p; 
    }
    g[x] = (g[x] - G(x-1)*G(x-1)%p + p)%p;
    return g[x];
}
long long F(int x){
    if(x == 1)return 1;
    if(f[x] != -1)return f[x];
    f[x] = 1;
    for(int i = 1; i < x; ++i){
        f[x] = (f[x] + F(i)*G(i)%p)%p; 
    }
    return f[x];
}

int main(){
    while(true){
        scanf("%lld%lld",&n,&p);
        if(n == 0 && p == 0)return 0;
        memset(f,-1,sizeof(f));
        memset(g,-1,sizeof(g));
        f[1] = 1, g[1] = 1;
        printf("%lld\n",F(n));
    }
    return 0;
}