//https://codeforces.com/contest/383/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N = 1010, M = 10010,mod=1e9+7,zero = 15015;
int dp[N][3*M],a[N],n,ans;

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%d",a+i);
    for(int i = 1; i <= n; ++i){
        dp[i][a[i]+zero]++;
        dp[i][-a[i]+zero]++;
        for(int sum = -M; sum <= M; ++sum){
            dp[i][zero+sum] += dp[i-1][zero+sum-a[i]];
            dp[i][zero+sum] %= mod;
            dp[i][zero+sum] += dp[i-1][zero+sum+a[i]];
            dp[i][zero+sum] %= mod;
        }
        ans += dp[i][zero];
        ans%=mod;
    }
    printf("%d",ans);
    return 0;
}