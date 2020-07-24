//https://codeforces.com/contest/449/problem/D
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const int N = (1 << 20), LN = 20;
ll f[N];
int n,a;

ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    ll p = power(a,n>>1);
    p = p * p % mod;
    if(n & 1)p = p * a % mod;
    return p;
}

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a);
        f[a]++;
    }
    for(int i = 0; i < LN; ++i){
        for(int j = 0; j < N; ++j){
            if(((j >> i)&1) == 0)continue;
            int nxt = (j & (INT_MAX ^ (1 << i)));
            f[nxt]+=f[j];      
            if(f[nxt] >= mod)f[nxt]-=mod;
        }
    }
    ll ans = 0;
    int cnt = 0;
    for(int j = 0; j < N; ++j){
        if(__builtin_popcount(j)%2){
            ans = (ans - power(2,f[j]) + mod) % mod;
        }else{
            ans = (ans + power(2,f[j]) + mod) % mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}