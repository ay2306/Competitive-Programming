//https://codeforces.com/contest/145/problem/C
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long dp[2100][2100],fct[200000],inv[200000],ans;
int other,c,n,k,x,f[2100];
bool isLucky(int x){
    while(x){
        if(x%10 != 4 && x%10 != 7)return false;
        x/=10;
    }
    return true;
}

long long power(long long a, long long n){
    if(n == 0)return 1;
    if(n == 1)return a;
    long long p = power(a,n>>1);
    p = p * p % mod;
    if(n & 1)p = p * a % mod;
    return p;
}

long long ncr(int n, int r){
    if(r < 0 || r > n)return 0LL;
    return fct[n] * inv[r] % mod * inv[n-r] % mod;
}

int main(){
    fct[0] = 1;
    fct[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for(long long i = 2; i < 200000; ++i)fct[i] = fct[i-1] * i % mod, inv[i] = inv[i-1] * power(i,mod-2) % mod;
    map<int,int> mp;
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; ++i){
        scanf("%d",&x);
        if(!isLucky(x)){
            other++;
            continue;
        }
        if(mp.count(x) == 0)mp[x]=++c;
        f[mp[x]]++;
    }
    dp[0][0] = 1;
    for(int i = 1; i < 1100; ++i){
        dp[i][0] = 1;
        for(int len = 1; len < 1100; ++len){
            dp[i][len] = (dp[i-1][len] + dp[i-1][len-1]*1LL*f[i] % mod)%mod;
        }
    }
    for(int len = 0; len <= k && len <= c; ++len){
        ans += dp[c][len] * ncr(other,k-len) % mod;
        if(ans >= mod)ans-=mod;
    }
    return printf("%lld",ans),0;
}