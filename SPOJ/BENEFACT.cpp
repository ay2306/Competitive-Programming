#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
struct edge{
    int dis;
    int to;
    edge(int a, int b):dis(a),to(b){}
};
int d[N],n,a,b,c,t;
vector<edge> g[N];
int dfs(int s = 1, int p = -1){
    int mx = s;
    if(p == -1)d[s] = 0;
    for(edge &i: g[s]){
        if(i.to == p)continue;
        d[i.to] = d[s] + i.dis;
        int res = dfs(i.to,s);
        if(d[res] > d[mx])mx=res;
    }   
    return mx;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);        
        for(int i = 1; i <= n; ++i)g[i].clear();
        for(int i = 1; i < n; ++i){
            scanf("%d%d%d",&a,&b,&c);
            g[a].emplace_back(edge(c,b));
            g[b].emplace_back(edge(c,a));
        }
        int r = dfs(dfs(1));
        printf("%d\n",d[r]);
    }
    return 0;
}