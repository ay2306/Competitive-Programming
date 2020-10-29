#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> d;
vector<vector<pair<int,int>>> g;
vector<int> queries;
int n,m,k,x,y,w;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    g.resize(n+1);
    d.resize(n+1);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d",&x,&y,&w);
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
    for(auto &[a,b] : queries)
        scanf("%d%d",&a,&b);
    auto djikstra = [&](int source)->vector<int>{
        vector<int> dis(n+1,1e9);
        vector<int> vis(n+1,false);
        set<pair<int,int>> s;
        s.emplace(0,source);
        dis[source] = 0;
        while(s.size()){
            int u = s.begin()->second;
            s.erase(s.begin());
            if(vis[u])continue;
            vis[u] = true;
            for(auto& [v,_distance]: g[u]){
                if(dis[v] > dis[u] + _distance){
                    dis[v] = dis[u] + _distance;
                    s.emplace(dis[v],v);
                }
            }
        }
        return dis;
    };
    for(int i = 1; i <= n; ++i)
        d[i] = djikstra(i);
    int ans = 1e9;
    for(int )
    return 0;
}