#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9; 

struct dinic{
    struct edge{
        int u,v,flow,cap,req;
        edge(){}
        edge(int _u, int _v, int _cap, int _req):
            u(_u),v(_v),flow(0),cap(_cap),req(_req){}
    };
    vector<edge> e;
    vector<vector<int>> g;
    vector<int> point,level;
    queue<int> q;
    int n,m,source,sink;
    dinic(int _N, int _source, int _sink):
        n(_N),m(0),source(_source),sink(_sink),g(_N+1),point(_N+1),level(_N+1)
        {}
    void add(int u, int v, int cap, int req){
        e.emplace_back(u,v,cap,req);
        e.emplace_back(v,u,-cap,0);
        g[u].emplace_back(m++);
        g[v].emplace_back(m++);
    }
    bool bfs(){
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int index: g[u]){
                int v = e[index].v;
                if(e[index].cap - e[index].flow < 1)continue;
                if(level[v] != -1)continue;
                q.emplace(v);
                level[v] = level[u] + 1;
            }
        }
        cout << endl;
        return level[sink] != -1;
    }
    int dfs(int u, int push){
        if(push == 0)return 0;
        if(u == sink)return push;
        for(int &itr = point[u]; itr < (int)g[u].size(); ++itr){
            int index = g[u][itr];
            int v = e[index].v;
            if(level[v] != level[u] + 1 || e[index].cap - e[index].flow < 1)continue;
            int netPush = dfs(v, min(push, e[index].cap - e[index].flow));
            if(netPush == 0)continue;
            e[index].flow += netPush;
            e[index^1].flow -= netPush;
            return netPush;
        }
        return 0;
    }
    int flow(){
        int f = 0;
        while(true){
            fill(level.begin(),level.end(),-1);
            level[source] = 0;
            q.push(source);
            if(!bfs())break;
            fill(point.begin(),point.end(),0);
            while(int res = dfs(source, inf))f+=res;
        }
        return f;
    }
    void display(){
        for(int i = 0; i < e.size(); i+=2){
            cout << e[i].u << " " << e[i].v << " " << e[i].flow << " " << e[i].cap << " " << e[i].req << endl;
        }
    }
};

signed main(){
    int n,m;
    cin >> n >> m;
    dinic s(n+2,n+1,n+2);
    vector<int> in(n+1),out(n+1);
    while(m--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        s.add(a,b,c,d);
        in[a]++;
        out[b]++;
    }      
    for(int i = 1; i <= n; ++i){
        if(in[i] == 0)s.add(n+1,i,inf/2,0);
        if(out[i] == 0)s.add(i,n+2,inf,0);
    }
    cout << s.flow() << endl;
    s.display();
    return 0;
}