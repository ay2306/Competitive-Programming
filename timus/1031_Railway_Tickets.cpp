#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int l[3],c[3];
    for(int i = 0; i < 3; ++i)cin >> l[i];
    for(int i = 0; i < 3; ++i)cin >> c[i];
    int n;
    cin >> n;
    vector<int> arr(n+1,0);
    vector<int> dp(n+1,LLONG_MAX);
    int a,b;
    cin >> a >> b;
    if(a > b)swap(a,b);
    for(int i = 2; i <= n; ++i)cin >> arr[i];
    dp[a] = 0;
    for(int i = a+1; i <= b; ++i){
        for(int j = i-1; j >= a; --j){
            int diff = arr[i] - arr[j];
            if(diff > l[2])break;
            if(diff <= l[0])dp[i] = min(dp[i],dp[j]+c[0]);
            else if(diff <= l[1])dp[i] = min(dp[i],dp[j]+c[1]);
            else if(diff <= l[2])dp[i] = min(dp[i],dp[j]+c[2]);
        }
    }
    cout << dp[b];
    return 0;
}