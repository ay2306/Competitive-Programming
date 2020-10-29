#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod = 1e9+7;
const int INV = 500000004 ;
int sq, ans;
int rng(int l, int r){
    l = max(l,sq);
    r = max(r,sq);
    int right = r % mod * ((r + 1)%mod) % mod * INV % mod;
    int left = l % mod * ((l + 1)%mod) % mod * INV % mod;
    return (right - left + mod ) % mod;
}
signed main(){
    int n;
    cin >> n;
    sq = sqrtl(n);
    ans = 0;
    for(int i = 1; i <= sq; ++i){
        ans += (n / i) * i % mod;
        if(ans >= mod)ans-=mod;
        ans += rng(n/(i+1),n/i) * i % mod;
        if(ans >= mod)ans-=mod;
    }
    return cout << ans , 0;
}