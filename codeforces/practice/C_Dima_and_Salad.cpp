#include<bits/stdc++.h>
using namespace std;
const int base = 150000;
int n,k,dp[110][300100],a[110],b[110];

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i)scanf("%d",a+i);
    for(int i = 1; i <= n; ++i)scanf("%d",b+i);
    for(int i = 1; i <= n; ++i)b[i]*=k;
    memset(dp,-1,sizeof(dp));
    dp[0][base] = 0;
    for(int i = 1; i <= n; ++i){
        for(int diff = 0; diff < 2*base; ++diff){
            dp[i][diff] = dp[i-1][diff];
            int added = a[i]-b[i];
            if(diff - added >= 0 && ~dp[i-1][diff-added])dp[i][diff] = max(dp[i][diff],dp[i-1][diff-added]+a[i]);
        }
    }
    if(!dp[n][base])return printf("-1"),0;
    return printf("%d",dp[n][base]),0;
}