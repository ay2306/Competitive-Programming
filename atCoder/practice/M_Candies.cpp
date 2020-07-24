#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int M = 1e5+10;
int dp[2][M];
int main(){
    int n,k,a;
    cin >> n >> k;
    fill(dp[0],dp[0]+M,1);
    for(int i = 1; i <= n; ++i){
        cin >> a;
        for(int j = 0; j <= k; ++j){
            int r = j;
            int l = max(j-a,0);
            dp[i&1][j] = dp[i&1^1][r] - (l ? dp[i&1^1][l-1] : 0);
            if(dp[i&1][j] < 0)dp[i&1][j] += mod;
        }
        if(i != n){
            for(int j = 1; j <= k; ++j){
                dp[i&1][j] += dp[i&1][j-1];
                if(dp[i&1][j] >= mod)dp[i&1][j]-=mod;
            }
        }
    }
    cout << dp[n&1][k];
    return 0;
}