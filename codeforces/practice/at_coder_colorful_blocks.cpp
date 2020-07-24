#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod = 998244353, N = 2e5+100;
ll dp[N];
ll incorrect[N];
ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    ll p = power(a,n/2);
    p = p*p%mod;
    if(n&1)p = p *a%mod;
    return p;
}
int main(){
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    dp[0] = m;
    k++;
    if(m == 1 && k < n){
        return cout << "0\n",0;
    }else if(m == 1)return cout << "1\n",0;
    ll val = 0;
    if(k == 1){
        cout << power(n-1,m-1)*m%mod;
        return 0;
    }
    for(ll i = 2; i < k; ++i){
        val = (val + power(k-i,m)*(m-1)%mod)%mod;
    }
    dp[0] = m;
    incorrect[k] = m;
    // cout << val << "\n";
    for(int i = 1; i < n; ++i){
        dp[i] = dp[i-1]*m%mod;
        if(i-k >= 0)dp[i] = (dp[i] - dp[i-k]*(m-1)%mod + mod)%mod;
        // if(i-k >= 0)dp[i] = (dp[i] - dp[i-k]*(m-1)%mod + mod)%mod;
    }
    return cout << dp[n-1] << "\n",0;
}