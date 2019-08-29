#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > adj;
vector<int> dist;
int n;  
unordered_map<string,int> m;

void dijkstra(int s){
    vector<bool> vis(n,false);
    dist = vector<int> (n,-1);
    multiset<pair<int,int> > ms;
    dist[s] = 0;
    ms.insert(make_pair(0,s));
    while(ms.size()){
        auto l = ms.begin();
        int u = l->second;
        ms.erase(ms.begin());
        if(vis[u])continue;
        vis[u] = true;
        for(auto i: adj[u]){
            int d = i.first;
            int v = i.second;
            if(vis[v])continue;
            if(dist[v] == -1 || dist[v] > dist[u] + d){
                ms.insert(make_pair(dist[u]+d,v));
                dist[v] = dist[u]+d;
            }
        }
    }
}

void solve(){
    cin >> n;
    adj = vector<vector<pair<int,int> > > (n);
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        m[a] = i;
        int k;
        cin >> k;
        while(k--){
            int nr,cst;
            cin >> nr >> cst;
            nr--;
            adj[i].push_back(make_pair(cst,nr));
        }
    }
    int r;
    cin >> r;
    while(r--){
        string a,b;
        cin >> a >> b;
        int e,f;
        e = m[a];
        f = m[b];
        dijkstra(e);
        cout << dist[f] << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}