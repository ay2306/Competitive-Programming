#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int b,n,ans = 0;
    scanf("%lld",&n);
    map<int,int> dp;
    for(int i = 0; i < n; ++i){
        scanf("%lld",&b);
        dp[b-i]+=b;
        ans = max(dp[b-i],ans);
    }
    printf("%lld\n",ans);
    return 0;
}