//https://codeforces.com/problemset/problem/1334/E
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const int N = 50000;
ll inv[N],fct[N];

inline ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    ll p = power(a,n>>1);
    p = p * p % mod;
    if ( n & 1 )p = p * a % mod;
    return p;
}
ll d,x,Q,a,b,g;
map<ll,map<ll,ll>> prime;
int main(){
    inv[0] = 1;
    inv[1] = 1;
    fct[0] = 1;
    fct[1] = 1;
    for(ll i = 2; i < N; ++i)fct[i] = i*fct[i-1]%mod,inv[i] = inv[i-1]*power(i,mod-2)%mod;
    scanf("%lld",&d);
    x = d;
    for(ll i = 2; i*i <= x; ++i){
        if(d%i) continue;
        while(x%i == 0)prime[d][i]++,x/=i;
    }
    if(x > 1)prime[d][x]++;
    queue<ll> q;
    q.push(d);
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(auto &i: prime[u]){
            if(i.second == 0)continue;
            ll v = u/i.first;
            if(prime.count(v))continue;
            prime[v] = prime[u];
            prime[v][i.first]--;
            q.push(v);
        }
    }
    scanf("%lld",&Q);
    while(Q--){
        scanf("%lld %lld",&a,&b);
        if(a > b)swap(a,b);
        g = __gcd(a,b);
        ll denominator = 1;
        ll numerator = 1;
        ll s = 0;
        for(auto &i: prime[a]){
            denominator = denominator * inv[i.second - prime[g][i.first]] % mod;
            s+=i.second-prime[g][i.first];
        }
        numerator = numerator * fct[s] % mod;
        s = 0;
        for(auto &i: prime[b]){
            denominator = denominator * inv[i.second - prime[g][i.first]] % mod;
            s+=i.second-prime[g][i.first];
        }
        numerator = numerator * fct[s] % mod;
        printf("%lld\n",numerator * denominator % mod);
    }
    return 0;
}