#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n,k;
    cin >> n >> k;
    long long ans = (n+k-1)/k*k;
    if(ans == n)ans+=k;
    cout << ans;
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