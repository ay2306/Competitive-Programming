#include<bits/stdc++.h>
#define ld long double
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<ld>> p(n,vector<ld>(n));
    for(auto &i: p)
        for(auto &j: i)cin >> j;
    vector<vector<ld>> dp(1 << n,vector<ld>(n,0));
    for(int i = 0; i < n; ++i)dp[1<<i][i] = 1.0;
    for(int mask = 1; mask < (1<<n); ++mask){
        if(__builtin_popcount(mask) == 1)continue;
        for(int i = 0; i < n; ++i){
            if(mask >> i & 1 ^ 1)continue;
            for(int j = 0; j < n; ++j){
                if(i == j)continue;
                if(mask >> j & 1 ^ 1)continue;
                ld res = 0;
                res += dp[mask^(1<<i)][j] * p[i][j] / (__builtin_popcount(mask)-1);
                res += dp[mask^(1<<j)][i] * p[i][j] / (__builtin_popcount(mask)-1);
                dp[mask][i] = max(dp[mask][i],res);
            }
        }
    }
    cout << fixed << setprecision(10) << dp[(1<<n)-1][0];    
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