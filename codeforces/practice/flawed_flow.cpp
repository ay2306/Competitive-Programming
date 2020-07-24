//https://codeforces.com/contest/269/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int f[N],c,a,b,n,m;
set<pair<int,int>> s;
vector<pair<int,int>> e,g[N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < m; ++i){
        scanf("%d%d%d",&a,&b,&c);
        f[a]+=c;
        f[b]+=c;
        e.emplace_back(a,b);
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    for(int i = 1; i <= n; ++i)f[i]>>=1;
    queue<int> q;
    q.emplace(1);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(s.count({v.first,u}) + s.count({u,v.first}))continue;
            s.emplace(u,v.first);
            f[v.first] = f[v.first] - v.second;
            if (v.first != n && f[v.first] == 0)q.emplace(v.first);
        }
    }
    for(auto &i: e){
        if(s.count(i))printf("0\n");
        else printf("1\n");
    }
    return 0;
}