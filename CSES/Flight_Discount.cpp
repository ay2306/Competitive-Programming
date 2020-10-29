#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10,inf=LLONG_MAX>>14;
vector<pair<int,int>> g[N];
vector<pair<int,int>> g2[N];
int n,m;
void dijkstra(int s, vector<int> &dis, bool rev = false){
    fill(dis.begin(),dis.end(),inf);
    dis[s] = 0;
    rev = s == n;
    vector<bool> vis(n+1,false);
    multiset<pair<int,int>> q;
    q.emplace(0,s);
    while(q.size()){
        int u,dist;
        tie(dist,u) = *q.begin();
        q.erase(q.begin());
        if(vis[u])continue;
        vis[u] = true;
        if(!rev){
            for(auto& [v,x]: g[u]){
                if(vis[v])continue;
                if(dis[v] > dis[u] + x){
                    dis[v] = dis[u] + x;
                    q.emplace(dis[v],v);
                }
            }
        }
        if(rev){
            for(auto& [v,x]: g2[u]){
                if(vis[v])continue;
                if(dis[v] > dis[u] + x){
                    dis[v] = dis[u] + x;
                    q.emplace(dis[v],v);
                }
            }
        }
    }
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
        g2[b].emplace_back(a,c);
    }
    vector<int> d1(n+1),d2(n+1);
    dijkstra(1,d1);
    dijkstra(n,d2);
    int ans = inf;
    for(int i = 1; i <= n; ++i){
        for(auto& [j,x]: g[i]){
            ans = min({ans,d1[i]+d2[j]+x/2});
        }
    }
    cout << ans;
    return 0;
}