#include<bits/stdc++.h>
using namespace std;

vector<int> g[110];
int vis[110],a,b,n,m,del,p=-1,cur,u;

int dfs(int u, int p = -1, int col = 1){
    int res = 1;
    vis[u] = col;
    for(int i: g[u]){
        if(i == p)continue;
        if(vis[i] == 0)res+=dfs(i,u,3-col);
        else if(vis[i] == col)del++;
    }
    vis[u] = -vis[u];
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    a = 0, b = 0;
    for(int i = 1; i <= n; ++i){
        if(vis[i])continue;
        del = 0;
        int res = dfs(i);
        if(a > b)swap(a,b);
        a+=(res+1-del)/2,b+=(res-del)/2;
    }
    return printf("%d\n",n-2*min(a,b)),0;
}