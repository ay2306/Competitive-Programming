#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,n;
    scanf("%d%d",&r,&n);
    vector<int> t(n+1),x(n+1),y(n+1),dp(n+1,-1e9);
    x[0] = 1, y[0] = 1, dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d%d",&t[i],&x[i],&y[i]);
        for(int j = max(0,i-4*r); j < i; ++j){
            if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= t[i]-t[j])dp[i] = max(dp[i],1+dp[j]);
        }
    }
    return printf("%d",*max_element(dp.begin(),dp.end())), 0;
}