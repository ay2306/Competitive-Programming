#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
int lev[N], par[N];
vector<int> g[N];

int dfs(int s, int p = -1){
    lev[s] = (~p ? lev[p] + 1 : 0);
    par[s] = p;
    int mx = s;
    for(int i: g[s]){
        if(p == i)continue;
        int res = dfs(i,s);
        if(lev[res] > lev[mx])mx = res;
    }
    return mx;
}

int main(){
    int n,a,b;
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    set<int> s;
    int node = dfs(dfs(1));
    int dia = lev[node];
    for(int i = 1; i <= n; ++i)if(lev[i] == dia)s.emplace(i);
    node = dfs(node);
    for(int i = 1; i <= n; ++i)if(lev[i] == dia)s.emplace(i);
    for(int i = 1; i <= n; ++i)
        printf("%d\n",dia + (s.count(i)));
    return 0;
}