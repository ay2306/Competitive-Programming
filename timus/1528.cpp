#include<bits/stdc++.h>
const int N = 1e4+10;
long long f[N],g[N],pfg[N],pgg[N];

int main(){
    int n,p;
    while(true){
        scanf("%d%d",&n,&p);
        if(n == 0 && p == 0)return 0;
        f[1] = 1, g[1] = 1, pfg[1] = 1, pgg[1] = 1;
        for(int i = 2; i <= n; ++i){
            f[i] = (1+pfg[i-1])%p;
            g[i] = (1+2*pgg[i-1]-g[i-1]*g[i-1]%p+p)%p;
            pfg[i] = (pfg[i-1] + f[i]*g[i]%p)%p;
            pgg[i] = (pgg[i-1] + g[i])%p;
        }   
        printf("%lld\n",f[n]);
    }
    return 0;
}