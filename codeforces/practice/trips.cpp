//https://codeforces.com/problemset/problem/1037/E
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<pair<int,int>> edges,g[N];
vector<int> ans;
set<pair<int,int>> s;
set<int> deleted;
int n,m,k,a,b,deg[N];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&a,&b);
        edges.emplace_back(a,b);
        deg[a]++;
        deg[b]++;
        g[a].emplace_back(b,i);
        g[b].emplace_back(a,i);
    }
    for(int i = 1; i <= n; ++i)s.emplace(deg[i],i);
    for(int ind = m-1; ind >= 0; --ind){
        while(s.size() && s.begin()->first < k){
            int u = s.begin()->second;
            s.erase(s.begin());
            deleted.insert(u);
            for(auto &i:g[u]){
                int v = i.first;
                if(i.second > ind)continue;
                if(!deleted.count(v)){
                    s.erase({deg[v],v});
                    --deg[v];
                    s.insert({deg[v],v});
                }
            }
        }
        ans.emplace_back((int)s.size());
        int x,y;
        tie(x,y) = edges[ind];
        if(!deleted.count(x) && !deleted.count(y)){
            s.erase({deg[x],x});
            deg[x]--;
            s.insert({deg[x],x});
            s.erase({deg[y],y});
            deg[y]--;
            s.insert({deg[y],y});
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto &i: ans)printf("%d\n",i);
    return 0;
}