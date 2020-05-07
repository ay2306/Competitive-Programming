#include<bits/stdc++.h>
using namespace std;

struct DINIC{
    struct Flow{
        int from, to;
        long long flow,cap;
        Flow(){}
        Flow(int u, int v, long long cap):from(u),to(v),flow(0),cap(cap){}
    };
    vector<int> level,ptr;
    vector<vector<int>> g;
    vector<Flow> edge;
    int n,m,s,t;
    queue<int> q;
    DINIC(int n, int s, int t){
        this->n = n;
        this->s = s;
        this->t = t;
        m = 0;
        g.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void addEdge(int a, int b, long long cap){
        edge.emplace_back(a,b,cap);
        edge.emplace_back(b,a,0);
        g[a].emplace_back(m);
        g[b].emplace_back(m+1);
        m+=2;
    }
    bool bfs(){
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int &i: g[u]){
                if(edge[i].cap-edge[i].flow < 1)continue;
                if(level[edge[i].to] != -1)continue;
                level[edge[i].to] = level[u] + 1;
                q.push(edge[i].to);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int u, long long pushed){
        if(!pushed)return 0;
        if(u == t)return pushed;
        for(int &i = ptr[u]; i < (int)g[u].size(); ++i){
            int id = g[u][i];
            int v = edge[id].to;
            if(level[v] != level[u]+1 || edge[id].cap-edge[id].flow < 1)continue;
            long long tr = dfs(v,min(pushed,edge[id].cap-edge[id].flow));
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
            while(long long push = dfs(s,LLONG_MAX))f+=push;
        }
        return f;
    }
    void display_answer(int n){
        vector<vector<long long>> ans(n,vector<long long>(n,0));
        for(int i = n; i < 2*n; ++i){
            for(auto &j: g[i]){
                if(edge[j].to==t && edge[j].flow != edge[j].cap){
                    printf("NO\n");
                    return;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(auto &j: g[i]){
                ans[i][edge[j].to-n] = edge[j].flow;
            }
        }
        printf("YES\n");
        for(auto &i: ans){
            for(auto &j: i)printf("%lld ",j);
            printf("\n");
        }
    }
};


int main(){
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    int source = 2*n, sink = 2*n+1;
    vector<long long> a(n),b(n);
    for(auto &i : a)scanf("%lld",&i);
    for(auto &i : b)scanf("%lld",&i);
    long long s1 = accumulate(a.begin(),a.end(),0LL);
    long long s2 = accumulate(b.begin(),b.end(),0LL);
    if(s1 != s2)return printf("NO\n"),0;
    DINIC flow(2*n+2,source,sink);
    while(m--){
        scanf("%d%d",&u,&v);
        u--,v--;
        flow.addEdge(u,v+n,LLONG_MAX);
        flow.addEdge(v,u+n,LLONG_MAX);
    }
    for(int i = 0; i < n; ++i){
        flow.addEdge(i,i+n,LLONG_MAX);
        flow.addEdge(source,i,a[i]);
        flow.addEdge(i+n,sink,b[i]);
    }
    long long s3 = flow.flow();
    if(s1 != s3)return printf("NO\n"),0;
    flow.display_answer(n);
    return 0;
}