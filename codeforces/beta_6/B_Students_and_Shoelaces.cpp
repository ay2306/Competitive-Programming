#include<bits/stdc++.h>
using namespace std;

vector<int> g[101];
int vis[101],in[101],lev[101];

int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        in[a]++;
        in[b]++;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    queue<int> q;
    map<int,int> tp;
    for(int i = 1; i <= n; ++i)
        if(in[i] == 1)q.push(i);
    int lev = 0, sz = 0;
    while(q.size() || tp.size()){
        if(sz == 0){
            for(auto &[u,f]: tp){
                in[u]-=f;
                if(in[u] == 1)q.push(u);
            }
            tp.clear();
            sz = q.size(),lev+=!q.empty();
        }
        if(sz == 0)break;
        int u = q.front();
        q.pop();
        sz--;
        in[u]--;
        for(int i : g[u]){
            if(in[i] > 1)tp[i]++;
        }
    }
    cout << lev ;
    return 0;
}