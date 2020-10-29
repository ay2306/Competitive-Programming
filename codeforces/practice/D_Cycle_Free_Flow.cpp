#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b,c,q;
    scanf("%d%d",&n,&m);
    vector<vector<pair<int,int>>> g;
    [&](void)->void{
        vector<pair<int,pair<int,int>>> e;
        vector<int> p(n+1);
        g.resize(n+1);
        iota(p.begin(),p.end(),0);
        function<int(int)> findParent = [&](int x)->int{
            if(p[x] != x)p[x] = findParent(p[x]);
            return p[x];
        };
        function<void(int,int)> join = [&](int a, int b)->void{
            p[findParent(a)] = findParent(b);
        };
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d",&a,&b,&c);
            e.emplace_back(c,make_pair(a,b));
        }
        sort(e.rbegin(),e.rend());
        for(auto& [w,x]: e){
            if(findParent(x.first) != findParent(x.second)){
                g[x.first].emplace_back(w,x.second);
                g[x.second].emplace_back(w,x.first);
                join(x.first,x.second);
            }
        }
    }();
    auto lev = vector<int> (n+1);
    auto dp = vector<vector<int>> (n+1,vector<int> (20,0));
    auto mx = vector<vector<int>> (n+1,vector<int> (20,INT_MAX));
    function<void(int,int)> dfs = [&](int s, int p)->void{
        for(auto i: g[s]){
            if(i.second == p)continue;
            mx[i.second][0] = i.first;
            dp[i.second][0] = s;
            lev[i.second] = lev[s] + 1;
            dfs(i.second,s);
        }
    };
    function<int(int,int)> getMinPath = [&](int a, int b)->int{
        if(lev[a] > lev[b])swap(a,b);
        int ans = INT_MAX,diff = lev[b] - lev[a];
        for(int i = 0; i < 20; ++i){
            if(diff>>i&1){
                ans = min(ans,mx[b][i]);
                b = dp[b][i];
            }
        }
        if(a == b)return ans;
        for(int i = 19; ~i; --i){
            if(dp[a][i] == dp[b][i])continue;
            ans = min({ans,mx[a][i],mx[b][i]});
            a = dp[a][i];
            b = dp[b][i];
        }
        return min({ans,mx[a][0],mx[b][0]});
    };
    dfs(1,-1);
    for(int j = 1; j < 20; ++j)
        for(int i = 1; i <= n; ++i){
            mx[i][j] = min(mx[i][j-1],mx[dp[i][j-1]][j-1]);
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&a,&b);
        printf("%d\n",getMinPath(a,b));
    }
    return 0;
}