//https://codeforces.com/contest/1343/problem/E
#include<bits/stdc++.h>
using namespace std;
int t,n,m,a,b,c,from,to;

void bfs(int s, vector<vector<int>> &g, vector<int> &lev){
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(s);
    lev[s] = 0;
    vis[s] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int &v: g[u]){
            if(!vis[v]){
                lev[v] = lev[u]+1;
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

void solve(){
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
    long long ans = LLONG_MAX;
    vector<vector<int>> g(n);
    vector<int> levA(n),levB(n),levC(n);
    vector<long long> cost(m+1,0);
    for(int i = 1; i <= m; ++i)scanf("%lld",&cost[i]);
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&to,&from);
        g[to-1].emplace_back(from-1);
        g[from-1].emplace_back(to-1);
    }
    bfs(a-1,g,levA);
    bfs(b-1,g,levB);
    bfs(c-1,g,levC);
    sort(cost.begin(),cost.end());
    for(int i = 1; i <= m; ++i)cost[i]+=cost[i-1];
    #ifdef LOCAL
    for(long long &i: cost)printf("%lld ",i);
    printf("\n");
    #endif
    for(int x = 0; x < n; ++x){
        int cst = levA[x] + levB[x] + levC[x];
        #ifdef LOCAL
        printf("x = %d , A = %d, B = %d, C = %d, cst = %d, pathcost = %d\n",x,a-1,b-1,c-1,cst,cost[cst]+cost[levB[x]]);
        #endif
        if(cst > m)continue;
        ans = min(ans,cost[cst]+cost[levB[x]]);
    }
    printf("%lld\n",ans);
}

int main(){
    scanf("%d",&t);
    #ifdef LOCAL
        t = 1;
    #endif
    while(t--)solve();
    return 0;
}