//https://codeforces.com/contest/732/problem/F
#include<bits/stdc++.h>
#define time asdadsa
using namespace std;
const int N = 4e5+10;
set<pair<int,int>> bridges;
int time, low[N], dis[N], dsuParent[N], dfsParent[N];
int n,m,a,b;
vector<int> g[N];
vector<pair<int,int>> edges;
set<pair<int,int>> directed_edges;

bool comp(const int &a, const int &b){
    return dsuParent[a] < dsuParent[b];
}

int findParent(int x){
    if(dsuParent[x] < 0)return x;
    dsuParent[x] = findParent(dsuParent[x]);
    return dsuParent[x];
}

void join(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b)return;
    if(dsuParent[a] < dsuParent[b])swap(a,b);
    dsuParent[b]+=dsuParent[a];
    dsuParent[a] = b;
}

void dfs(int s = 1, int p = -1){
    dis[s] = low[s] = ++time;
    dfsParent[s] = p;
    for(int &i: g[s]){
        if(i == p)continue;
        if(!low[i])dfs(i,s);
        // back-edge
        if(dis[s] < low[i]){
            bridges.insert(make_pair(s,i));
            bridges.insert(make_pair(i,s));
        }
        low[s] = min(low[s],low[i]);
    }
}

void assignOrientation(int s, int p = -1){
    low[s] = ++time;
    // printf("dfs node = %d\n",s);
    for(int &i: g[s]){
        if(i == p)continue;
        if(bridges.count(make_pair(i,s)))directed_edges.insert(make_pair(i,s));
        if(directed_edges.count(make_pair(i,s)) == 0)directed_edges.insert(make_pair(s,i));
        if(!low[i]){
            assignOrientation(i,s);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        edges.emplace_back(a,b);
    }
    for(int i = 1; i <= n; ++i)if(!low[i])dfs(i);
    memset(dsuParent,-1,sizeof(dsuParent));
    for(auto &i: edges){
        if(!bridges.count(i))join(i.first,i.second);
    }
    vector<int> nodesOrder;
    for(int i = 1; i <= n; ++i){
        nodesOrder.emplace_back(i);
    }
    sort(nodesOrder.begin(),nodesOrder.end(),comp);
    time = 0;
    memset(low,0,sizeof(low));
    for(int i = 0; i < n; ++i)if(!low[nodesOrder[i]])assignOrientation(nodesOrder[i]);
    for(auto &i: edges){
        if(directed_edges.count(i) == 0)swap(i.first,i.second);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)ans = max(ans,-dsuParent[i]);
    printf("%d\n",ans);
    for(auto &i: edges)printf("%d %d\n",i.first,i.second);
    return 0;
}