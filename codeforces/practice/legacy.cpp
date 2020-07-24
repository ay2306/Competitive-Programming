//https://codeforces.com/contest/786/problem/B
#include<bits/stdc++.h>
#define ll long long int
#define PLL pair<long long, long long>
using namespace std;
const ll N = 1e5+10, inf = LLONG_MAX >> 10;
int n,s,q,t,l,r,v;
ll dis[N*10],c,base=4*N+10;
vector<PLL> g[N*10];
vector<int> collection;
bool vis[N*10];




void nodeCollection(int l, int r, int node = 1, int start = 1, int end = N){
    vector<int> ans;
    if(l > end || r  < start) return ;
    if(l <= start && end <= r){
        collection.emplace_back(node);
        return;
    }
    int mid = start+end >> 1;
    nodeCollection(l,r,node<<1,start,mid);
    nodeCollection(l,r,node<<1|1,mid+1,end);
}

int findNode(int id, int node = 1, int start = 1, int end = N){
    if(start == end)return node;
    int mid = start+end >> 1;
    if(mid >= id)return findNode(id,node << 1, start, mid);
    return findNode(id,node<<1|1,mid+1,end);
}

void dfs(int node = 1, int start = 1, int end = N){
    g[node].emplace_back(0,node+base);
    if(start == end) return;
    g[node].emplace_back(0,node<<1);
    g[node].emplace_back(0,node<<1|1);
    g[(node<<1)+base].emplace_back(0,node+base);
    g[(node<<1|1)+base].emplace_back(0,node+base);
    int mid = start + end >> 1;
    dfs(node << 1, start, mid);
    dfs(node << 1 | 1, mid+1, end);
}

int main(){
    scanf("%d%d%d",&n,&q,&s);
    dfs();
    while(q--){
        scanf("%d",&t);
        if(t == 1){
            scanf("%d%d%lld",&l,&r,&c);
            l = findNode(l);
            r = findNode(r);
            g[l].emplace_back(c,r);
        }
        if(t == 2){
            scanf("%d%d%d%lld",&v,&l,&r,&c);
            int node = findNode(v);
            collection.clear();
            nodeCollection(l,r);
            for(auto &i: collection){
                g[node].emplace_back(c,i);
            }
        }
        if(t == 3){
            scanf("%d%d%d%lld",&v,&l,&r,&c);
            int node = findNode(v);
            collection.clear();
            nodeCollection(l,r);
            for(auto &i: collection){
                g[i+base].emplace_back(c,node);
            }
        }
    }
    multiset<PLL> m;
    for(int i = 0; i < N*10; ++i)dis[i] = inf;
    s = findNode(s);
    dis[s] = 0;
    m.insert(PLL(0,s));
    while(!m.empty()){
        int u = m.begin()->second;
        m.erase(m.begin());
        if(vis[u])continue;
        vis[u] = true;
        for(auto& [length, v]: g[u]){
            if(dis[v] > dis[u] + length){
                dis[v] = dis[u]+length;
                m.insert(PLL(dis[v],v));
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        int node = findNode(i);
        dis[node] == inf?printf("-1 "):printf("%lld ",dis[node]);
    }
    return 0;
}