#include<bits/stdc++.h>
using namespace std;

struct Dinic{
    struct Flow{
        int u, v;
        long long cap, flow;
        Flow(int u = 0, int v = 0, long long cap = 0, long long f = 0):u(u),v(v),cap(cap),flow(flow){}
    };
    const long long int inf = LLONG_MAX;
    vector <Flow> edge;
    vector<vector<int>> g;
    int n,m,s,t;
    vector<int> level,ptr;
    queue<int> q;

    Dinic(int n, int s, int t):n(n),s(s),t(t){
        g.resize(n);
        level.resize(n);
        ptr.resize(n);
        m = 0;
    }
    void add_edge(int u, int v, long long cap){
        edge.emplace_back(u,v,cap);
        edge.emplace_back(v,u,0);
        g[u].emplace_back(m);
        g[v].emplace_back(m+1);
        m+=2;
    }
    bool bfs(){
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &i: g[u]){
                if(edge[i].cap - edge[i].flow < 1)continue;
                if(level[edge[i].v] != -1)continue;
                level[edge[i].v] = level[u] + 1;
                q.push(edge[i].v);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int u, long long pushed){
        if(pushed == 0)return 0;
        if(u == t)return 0;
        for(int &i = ptr[u]; i < (int)g[u].size(); ++i){
            int id = g[u][i];
            int v = edge[id].v;
            if(level[u]+1 != level[v] || edge[id].cap - edge[id].flow < 1)continue;
            long long tr = dfs(u,min(pushed,edge[id].cap-edge[id].flow));
            if(tr == 0)continue;
            edge[id].flow += tr;
            edge[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    long long flow(){
        long long f = 0;
        while(true){
            fill(level.begin(),level.end(),-1);
            level[s] = 0;
            q.push(s);
            if(!bfs())break;
            fill(ptr.begin(),ptr.end(),0);
            while(long long pushed = dfs(s,inf))f+=pushed;
        }
        return f;
    }
};

int main(){
    return 0;
}