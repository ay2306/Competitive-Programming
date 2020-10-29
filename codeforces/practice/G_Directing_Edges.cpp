#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define edge pair<PII,int>
#define x first
#define y second
using namespace std;
const int N = 3e5+10;

int a,b,w,n,m,k;
vector<edge> g[N],ed;
set<edge> bridges;
int low[N],dis[N],tme,c[N];
set<int> special;

void findBrigdes(int s, int p = -1){
    low[s] = dis[s] = ++tme;
    for(auto &i: g[s]){
        int v = i.x.x ^ i.x.y ^ s;
        if(v == p)continue;
        if(dis[v] == 0){
            findBrigdes(v,s);
            if(dis[s] < low[v])bridges.emplace(i);
        }
        low[s] = min(low[s],low[v]);
    }
}

int32_t main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 0; i < k; ++i){
        scanf("%lld",&a);
        special.emplace(a);
    }
    for(int i = 1; i <= n; ++i)scanf("%lld",c+i);
    ed.resize(m);
    for(auto &i: ed)scanf("%lld",&i.y);
    for(auto &i: ed)scanf("%lld%lld",&i.x.x,&i.x.y);
    for(int i = 1; i <= n; ++i)if(dis[i] == 0)findBrigdes(i);
    return 0;
}