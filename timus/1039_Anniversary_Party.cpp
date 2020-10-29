#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    scanf("%d",&n);
    vector<int> arr(n+1),s(n+1,1);
    vector<vector<int>> g(n+1);
    for(int i = 1; i <= n; ++i)
        scanf("%d",&arr[i]);
    for(int i = 1; ; ++i){
        scanf("%d%d",&a,&b);
        if(!a)break;
        g[b].emplace_back(a);
        s[a] = false;   
    }
    vector<array<int,2>> dp(n+1,array<int,2>{0,0});
    function<void(int)> dfs = [&](int u)->void{
        for(int v: g[u]){
            dfs(v);
            dp[u][0] += max(dp[v][0],dp[v][1]);
            dp[u][1] += dp[v][0]; 
        }
        dp[u][1] += arr[u];
    };
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i]){
            dfs(i);
            ans+=max(dp[i][1],dp[i][0]);
        }
    }
    printf("%d",ans);
    return 0;
}