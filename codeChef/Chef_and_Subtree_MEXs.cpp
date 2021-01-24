#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,n;
        scanf("%d",&n);
        vector<vector<int>> g(n+1);
        for(int i = 2; i <= n; ++i){
            scanf("%d",&a);
            g[a].emplace_back(i);
            g[i].emplace_back(a);
        }
        vector<long long> sub(n+1),dp(n+1);
        function<void(int,int)> dfs = [&](int s, int p){
            sub[s] = 1;
            for(int i : g[s]){
                if(i == p)continue;
                dfs(i,s);
                sub[s] += sub[i];
                dp[s] = max(dp[s],dp[i]);
            }
            dp[s] += sub[s];
        };
        dfs(1,-1);
        printf("%lld\n",dp[1]);
    }
    return 0;
}