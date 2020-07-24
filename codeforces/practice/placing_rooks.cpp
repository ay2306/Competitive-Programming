//https://codeforces.com/contest/1342/problem/E
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 998244353;
const int N = 2e5+10;

ll power(ll a, ll n){
    ll ans = 1;
    if(a == 0)return 0;
    if(n == 0)return 1;
    while(n){
        if(n&1)ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
ll fct[N],inv[N];

ll ncr(ll n, ll r){
    if(r <= 0 || r > n)return 0;
    return fct[n] * inv[r] % mod * inv[n-r] % mod;
}

int main(){
    fct[0] = fct[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N ; ++i){
        fct[i] = fct[i-1] * i % mod;
        inv[i] = inv[i-1] * power(i,mod-2) % mod;
    }
    int n, k;
    cin >> n >> k;
    if(k == 0)cout << fct[n] << "\n";
    else{
        ll ans = 0;
        for(ll i = n-k; i >= 0; --i){
            if((n-k-i)%2 == 0){
                ans = (ans + ncr(n-k,i)*power(i,n)%mod)%mod;
            }else{
                ans = (ans - ncr(n-k,i)*power(i,n)%mod + mod)%mod;
            }
        }
        ans = ans * ncr(n,n-k) % mod;
        cout << 2LL*ans%mod << "\n";
    }

    return 0;
}