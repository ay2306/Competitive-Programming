#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> gas(n+1),par(n+1,-1);
    for(int i = 1; i <= n; ++i)cin >> gas[i];
    vector<vector<pair<int,int>>> g(n+1);
    map<pair<int,int>,int> m;
    for(int i = 1; i < n; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
        m[make_pair(a,b)] = c;
        m[make_pair(b,a)] = c;
    } 
    function<void(int,int)> dfs = [&](int u, int p)->void{
        par[u] = p;
        for(auto i: g[u]){
            if(i.first == p)continue;
            dfs(i.first,u);
        }
    };
    dfs(1,-1);
    vector<int> path;
    int cur = n;
    while(~cur){
        path.emplace_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(),path.end());
    for(int i: path)cout << i << " ";
    cout << endl;
    int ans = gas[1];
    for(int i = 1; i < path.size(); ++i){
        ans -= m[make_pair(path[i-1],path[i])];
        ans += gas[path[i]];
    }
    cout << ans;
    return 0;
}
