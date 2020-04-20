#include<bits/stdc++.h>
long long n,a,f[(int)2e5+10],s;
int main(){
    scanf("%lld",&n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld",&a);
        if(i&1)s+=a; // s is sum of odd indices
        if(i == 1)continue;
        if(i&1)f[i] = std::max(f[i-2]+a,f[i-1]); // at odd place either f[i-2]+a (common sense) or previous
        else f[i] = std::max(f[i-2]+a,s); // at even either normal or we just take odd ones
    }
    return printf("%lld\n",f[n]),0;
}