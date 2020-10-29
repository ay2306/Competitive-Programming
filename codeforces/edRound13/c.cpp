#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;
    int ans = 0;
    int lcm = a*b/__gcd(a,b);
    ans += p*(n/a - n/lcm);
    ans += q*(n/b - n/lcm);
    ans += max(p,q)*(n/lcm);
    cout << ans ;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}