#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<pair<int,int>> e;
vector<int> g[N],undirected;
int n,m;
int in[N],pos[N];
void solve(){
    e.clear();
    undirected.clear();
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i)g[i].clear();
    fill(in,in+n+1,0);
    fill(pos,pos+n+1,0);
    for(int i = 0; i < m; ++i){
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(t)g[a].emplace_back(i),in[b]++;
        else undirected.emplace_back(i);
        e.emplace_back(a,b);
    }
    int cur = 0;
    queue<int> q;
    for(int i = 1; i <= n; ++i)if(in[i] == 0)q.emplace(i);
    while(q.size()){
        int u = q.front();
        q.pop();
        in[u]--;
        pos[u] = cur++;
        for(int i: g[u]){
            int v = e[i].first ^ e[i].second ^ u;
            in[v]--;
            if(in[v] == 0)q.emplace(v);
        }
    }
    if(cur < n)return void(printf("NO\n"));
    for(auto i: undirected){
        if(pos[e[i].first] > pos[e[i].second])swap(e[i].first,e[i].second);
    }
    printf("YES\n");
    for(auto& [x,y]: e)printf("%d %d\n",x,y);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}