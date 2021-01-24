#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[2100][2100];

int32_t main(){
    int n,ans = 0;
    scanf("%lld",&n);
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; ++i){
        scanf("%lld",&arr[i].first);
        arr[i].second = -(i+1);
    }
    sort(arr.rbegin(),arr.rend());
    for(int l = 0; l < n; ++l){
        for(int r = 0; r+l < n; ++r){
            int val = arr[l+r].first;
            int index = -arr[l+r].second;
            dp[l+1][r] = max(dp[l+1][r], dp[l][r] + val*(abs(l+1-index)));
            dp[l][r+1] = max(dp[l][r+1], dp[l][r] + val*(abs(n-r-index)));
            if(l+r+1 == n){
                ans = max({dp[l+1][r],dp[l][r+1],ans});
            }
        }
    }
    printf("%lld",ans);
    return 0;
}