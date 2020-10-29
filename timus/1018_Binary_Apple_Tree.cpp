#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n,q,a,b,c,dp[N][N],v,w;
vector<pair<int,int>> g[N];

int main(){
    scanf("%d%d",&n,&q);
    for(int i = 1; i < n; ++i){
        scanf("%d%d%d",&a,&b,&c);
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    memset(dp,-1,sizeof(dp));
    function<void(int,int)> dfs = [&](int u, int p)->void{
        int l = -1, r = -1, lw,rw;
        for(auto edge: g[u]){
            if(edge.first == p)continue;
            dfs(edge.first,u);
            if(l == -1)tie(l,lw) = edge;
            else tie(r,rw) = edge;
        }
        if(g[u].size() == 1)return void(dp[u][0] = 0);
        for(int here = 0; here < n; ++here){
            for(int left = 0; left <= here; ++left){
                int right = here-left;
                int ans = 0;
                if(~l && left && ~dp[l][left-1])ans+=dp[l][left-1] + lw;
                if(~r && right && ~dp[r][right-1])ans+=dp[r][right-1] + rw;
                dp[u][here] = max(ans,dp[u][here]); 
            }
        }
    };
    dfs(1,-1);
    printf("%d",dp[1][q]);
    return 0;
}