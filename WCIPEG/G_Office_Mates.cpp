#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
int dp[N][3],vis[N];
void dfs(int u, int p = -1){
    vis[u] = true;
    if(~p)g[u].erase(find(g[u].begin(),g[u].end(),p));
    if(g[u].size() == 0){
        dp[u][0] = 1;
        return;
    }
    dp[u][0] = 1;
    for(int i : g[u])dfs(i,u);
    for(int i : g[u])dp[u][0] += *min_element(dp[i],dp[i]+3);
    int a = INT_MAX,b = INT_MAX;
    for(int i: g[u]){
        int cost = *min_element(dp[i],dp[i]+2) - *min_element(dp[i],dp[i]+3);
        if(cost < a){
            b = a;
            a = cost;
        }
        else if (cost <= b){
            b = cost;
        }
        dp[u][1] = min(dp[u][1],dp[u][0] + cost - 1);
    }
    if(g[u].size() > 1){
        dp[u][2] = dp[u][0] -  2 + a + b;
    }
}

void solve(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i)g[i].clear(),fill(dp[i],dp[i]+3,N);
    for(int i = 1; i <= m; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans = n-1;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i);
            ans += *min_element(dp[i],dp[i]+3);
        }
    }
    printf("%d\n",ans);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}