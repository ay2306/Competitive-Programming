#include<bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;

long long dp[110][110][110],fact[110],inv[110];

long long power(long long a, long long n){
    if(n == 1)return a%mod;
    if(n == 0)return 1;
    long long p = power(a,n>>1);
    p = p*p%mod;
    if(n&1)p=p*a%mod;
    return p;
}

long long ncr(long long n, long long r){
    if(r > n || r < 0)return 0;
    return fact[n]*inv[r]%mod*inv[n-r]%mod;
}

long long calculate(int rooms, int cricketers, int football){
    if(rooms == 0){
        return cricketers == 0 && football == 0;
    }
    long long &res = dp[rooms][cricketers][football];
    if(~res)return res;
    res = 0;
    for(int i = 2; i <= cricketers; ++i){
        res+=ncr(cricketers,i)*calculate(rooms-1,cricketers-i,football)%mod;
        res %= mod;
    }
    for(int i = 1; i <= football; ++i){
        res+=ncr(football,i)*calculate(rooms-1,cricketers,football-i)%mod;
        res %= mod;
    }
    return res;
}
int arr[100];
int main(){
    memset(dp,-1,sizeof(dp));
    fact[0] = fact[1] = 1; 
    inv[0] = inv[1] = 1; 
    for(int i = 2; i < 110; ++i){
        fact[i] = i*fact[i-1]%mod;
        inv[i] = inv[i-1]*power(i,mod-2)%mod;
    }
    int t,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        printf("%lld\n",calculate(c,b,a)*inv[c]%mod);
    }
    return 0;
}