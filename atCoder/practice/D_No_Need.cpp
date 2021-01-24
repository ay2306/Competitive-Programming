#include<bits/stdc++.h>
using namespace std;

const int N = 5002;

int main(){
    int n,k,arr[N],pref[N];
    bool dp[N][N],dpr[N][N];
    cin >> n >> k;
    memset(dp,0,sizeof(dp));
    memset(dpr,0,sizeof(dpr));
    for(int i = 1; i <= n; ++i)cin >> arr[i];
    dp[0][0] = true, dpr[n+1][0] = true;
    for(int i = 1; i <= n; ++i){
        for(int sum = 0; sum <= k; ++sum){
            dp[i][sum] = dp[i-1][sum];
            if(arr[i] <= sum)dp[i][sum] = dp[i][sum] || dp[i-1][sum - arr[i]];
        }
    }
    for(int i = n; i; --i){
        for(int sum = 0; sum <= k; ++sum){
            dpr[i][sum] = dpr[i+1][sum];
            if(arr[i] <= sum)dpr[i][sum] = dpr[i][sum] || dpr[i+1][sum - arr[i]];
        }
    }
    // for(int i = 0; i <= n; ++i){
    //     for(int sum = 0; sum <= k; ++sum)cout << dp[i][sum] << " ";
    //     cout << "\n";
    // }
    // cout << "-----------\n";
    // for(int i = 0; i <= n; ++i){
    //     for(int sum = 0; sum <= k; ++sum)cout << dpr[i][sum] << " ";
    //     cout << "\n";
    // }
    // cout << "-----------\n";
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int cnt = 0;
        if(arr[i] >= k)continue;
        int mn = k - arr[i], mx = k-1;
        pref[0] = 1;
        for(int j = 1; j <= k; ++j)pref[j] = pref[j-1] + dp[i-1][j];
        for(int sum = 0; sum <= mx; ++sum){
            int l = max(0,mn-sum), r = max(0,mx-sum);
            if(!dpr[i+1][sum])continue;
            if(pref[r] - pref[l-1]){
                cnt++;
                break;
            }
        }
        ans += (cnt == 0);
    }
    cout << ans;
    return 0;
}