//https://codeforces.com/problemset/problem/437/C
#include<bits/stdc++.h>
using namespace std;
const int N = 5050;
multiset<pair<int,int>> p;
vector<int> g[N];
int deg[N],n,a,b,m,ans,v[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i)scanf("%d",v+i);
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&a,&b);
        deg[a]++,deg[b]++;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i = 1; i <= n; ++i)p.emplace(v[i],i);
    while(m > 0){
        int u = p.begin()->second;
        p.erase(p.begin());
        if(deg[u] == 0)continue;
        while(deg[u] && m){
            deg[g[u].back()]--, deg[u]--,m--;
            g[u].pop_back();
            ans+=v[u];
        }
    }
    return printf("%d",ans),0;
}