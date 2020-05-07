//https://codeforces.com/contest/1097/problem/D
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long ans = 0;
long long inv[1000];
long long n,k;
long long power(long long a, long long n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    long long p = power(a,n>>1);
    p = p * p % mod;
    if(n & 1)p = p * a % mod;
    return p;
}

void calculate(long long p, long long mx){
    long long dp[10010][60], val[60];
    memset(dp,0LL,sizeof(dp));
    val[0] = 1;
    for(int i = 1; i <= mx; ++i)val[i] = val[i-1]*p%mod;
    // for(int i = 0; i <= mx; ++i)printf("power(%lld,%lld) = %lld\n",p,i,val[i]);
    dp[0][mx] = 1;
    // printf("prime = %lld, mx = %lld\n",p,mx);
    for(int i = 0; i < k; ++i){
        for(int j = mx; j >= 0; j--){
            for(int x = j; x >= 0; --x){
                dp[i+1][x] += dp[i][j]*inv[j+1]%mod;
                dp[i+1][x] %= mod;
                // printf("state = %d, current = %d, next = %d, prob = %lld\n",i,j,x,dp[i+1][x]);
            }
        }
    }
    long long res = 0;
    for(int i = 0; i <= mx; ++i)res = (res + dp[k][i]*val[i]%mod)%mod;
    // printf("%lld\n",res);
    ans = res*ans%mod;
}   

int main(){
    ans = 1;
    for(int i = 1; i < 1000; ++i)inv[i] = power(i,mod-2);
    scanf("%lld %lld",&n,&k);
    long long temp = n;
    for(long long i = 2; i * i <= temp; ++i){
        if(n%i)continue;
        int cnt = 0;
        while(n%i == 0){
            cnt++;
            n/=i;
        }
        calculate(i,cnt);
    }
    if(n > 1)calculate(n,1);
    printf("%lld\n",ans);
    return 0;
}