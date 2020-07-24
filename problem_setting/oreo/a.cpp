#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int LN = 20, N = 1e6;
int dp[N+100],n,a,q,x;
//dp[i] = number elements in array such that arr[k] | i = i;
long long power(long long a, long long n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    long long p = power(a,n>>1);
    p = p * p % mod;
    if(n & 1)p = p * a % mod;
    return p;
}
int main(){
    scanf("%d %d",&n,&q);
    long long inv = power(n,mod-2);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&a);
        dp[a]++;
    }
    for(int i = 0; i <= LN; ++i){
        for(int mask = 0; mask <= N; ++mask){
            if((mask >> i)&1)continue;
            int nxt = (mask | (1 << i));
            if(nxt <= N)dp[nxt] += dp[mask];
        }
    }
    while(q--){
        scanf("%d",&x);
        printf("%lld\n",dp[x]*1LL*inv%mod);
    }
    return 0;
}