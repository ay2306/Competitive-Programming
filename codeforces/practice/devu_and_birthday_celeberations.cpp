//https://codeforces.com/contest/439/problem/E
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
const ll N = 1e5+7;
ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n>>1);
    p = p * p % mod;
    if(n&1)p = p * a % mod;
    return p;
}

vector<int> fact;

ll fct[N], inv[N];
map<pair<int,int>,ll> dp;
ll ncr(ll n, ll r){
    if(r > n || r < 0)return 0;
    return fct[n] * inv[r] % mod * inv[n-r] % mod;
}

ll F(int n, int f){
    if(f > n)return 0;
    if(dp.count(make_pair(n,f)))return dp[make_pair(n,f)];
    dp[make_pair(n,f)] += ncr(n-1,f-1);
    for(int i: fact){
        if(n%i)continue;
        if(i!=1)dp[make_pair(n,f)] -= F(n/i,f);
        if(dp[make_pair(n,f)] < 0)dp[make_pair(n,f)] += mod;
    }
    return dp[make_pair(n,f)];
}

int main(){
    fct[0] = 1;
    inv[0] = 1;
    fct[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < N; ++i){
        fct[i] = i * fct[i-1] % mod;
        inv[i] = power(i,mod-2) * inv[i-1] % mod;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int n,f;
        scanf("%d%d",&n,&f);
        fact.clear();
        for(int i = 1; i*i <= n; ++i){
            if(n%i)continue;
            fact.emplace_back(i);
            if(i*i != n)fact.emplace_back(n/i);
        }
        printf("%lld\n",F(n,f));
    }
    return 0;
}