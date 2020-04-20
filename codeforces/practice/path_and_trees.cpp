//https://codeforces.com/problemset/problem/545/E
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3e5+10;
const int inf = 1e9;
int n,m,b,c,a,start;
vector<pair<ll,int>> g[N];
int parent[N],visited[N];
ll d[N],cst[N];
map<pair<int,int>,int> ind;
signed main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; ++i){
        scanf("%d%d%d",&a,&b,&c);
        g[a].emplace_back(c,b);
        g[b].emplace_back(c,a);
        ind[{a,b}] = i;
        ind[{b,a}] = i;
        cst[i] = c;
    }
    scanf("%d",&start);
    for(int i = 1; i < N; ++i)parent[i]=-1,d[i]=LLONG_MAX;
    multiset<pair<ll,int>> s;
    s.insert({0,start});
    d[start] = 0;
    while(s.size()){
        int u = s.begin()->second;
        ll dis = s.begin()->first;
        s.erase(s.begin());
        if(visited[u])continue;
        visited[u] = true;
        for(pair<ll,int> &i: g[u]){
            if(dis+i.first < d[i.second]){
                d[i.second] = dis+i.first;
                parent[i.second] = u;
                s.insert({d[i.second],i.second});
            }else if(dis+i.first == d[i.second] && cst[ind[{parent[i.second],i.second}]] > i.first)parent[i.second] = u;
        }
    }
    ll cost = 0; set<int> ans;
    for(int i = 1; i <= n; ++i){
        if(i == start)continue;
        ans.insert(ind[{parent[i],i}]);
        cost+=cst[ind[{parent[i],i}]];
    }
    printf("%lld\n",cost);
    for(auto &i: ans)printf("%d ",i);
}