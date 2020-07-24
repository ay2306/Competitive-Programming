//https://codeforces.com/contest/498/problem/C
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct Hopcraft_karp{
    int n;
    vector<int> matchL,matchR,dis;
    vector<vector<int>> g;
    Hopcraft_karp(int n):n(n),matchR(n+1),matchL(n+1),dis(n+1),g(n+1){}
    void add(int u, int v){
        g[u].emplace_back(v);}
    bool bfs(){
        queue<int> q;
        for(int i = 1; i <= n; ++i){
            if(!matchL[i]){
                dis[i] = 0;
                q.emplace(i); 
            }else dis[i] = inf;
        }
        dis[0] = inf;
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int v: g[u]){
                if(dis[matchR[v]] == inf){
                    dis[matchR[v]] = dis[u] + 1;
                    q.emplace(matchR[v]);
                }
            }
        }
        return dis[0] != inf;
    }
    bool dfs(int u){
        if(!u)return true;
        for(int v : g[u]){
            if(dis[matchR[v]] == dis[u]+1 && dfs(matchR[v])){
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        dis[u] = inf;
        return false;
    }
    int matching(){
        int ans = 0;
        while(bfs()){
            for(int i = 1; i <= n; ++i){
                if(!matchL[i] && dfs(i))ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<pair<int,int>> nodes;
    int n,a,m,b;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a;
        for(int j = 2; j*j <= a; ++j){
            if(a % j)continue;
            while(a%j == 0){
                nodes.emplace_back(j,i);
                a/=j;
            }
        }
        if(a > 1)nodes.emplace_back(a,i);
    }
    set<pair<int,int>> pr;
    while(m--){
        cin >> a >> b;
        pr.emplace(a,b);
        pr.emplace(b,a);
    }
    Hopcraft_karp s(nodes.size());
    for(int i = 0; i < nodes.size(); ++i){
        for(int j = i+1; j < nodes.size(); ++j){
            if(     nodes[i].first == nodes[j].first &&
                    (nodes[i].second & 1) != (nodes[j].second & 1) &&
                    pr.count({nodes[i].second,nodes[j].second})
            ){
                if(nodes[i].second & 1)s.add(i+1,j+1);
                else s.add(j+1,i+1);
            }
        }
    }
    cout << s.matching();
    return 0;
}