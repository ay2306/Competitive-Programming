//https://codeforces.com/problemset/problem/1228/C
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long power(long long a, long long n){
    if(n == 0 || a == 1)return 1;
    if(n == 1)return a%mod;
    long long p = power(a,n>>1);
    p = p*p%mod;
    if(n&1)p = p * a % mod;
    return p;
}

int main(){
    long long i,ans=1,x,n,p,cnt=0;
    scanf("%lld%lld",&x,&n);
    p = n;
    for(i = 2; i*i <= x; ++i,cnt=0,p=n){
        if(x % i)continue;
        while(x%i == 0)x/=i;
        for(;p/i;p/=i)cnt=(cnt+p/i)%(mod-1);
        ans = ans*power(i,cnt)%mod;
    }
    if(x > 1){
        for(;p/x;p/=x)cnt=(cnt+p/x)%(mod-1);
        ans = ans*power(x,cnt)%mod;
    }
    return cout << ans,0;
}