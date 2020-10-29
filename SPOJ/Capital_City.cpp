#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,cnt=0,timer=0;
    scanf("%d%d",&n,&m);
    vector<vector<int>> g(n+1);
    {
        vector<pair<int,int>> e;
        int a,b;
        while(m--){
            scanf("%d%d",&a,&b);
            e.emplace_back(a,b);
        }
        sort(e.begin(),e.end());
        e.resize(unique(e.begin(),e.end())-e.begin());
        for(auto i: e){
            g[i.second].emplace_back(i.first);
        }
    }
    stack<int> s;
    vector<int> dis(n+1),low(n+1),cyc(n+1),in_stack(n+1);
    auto popper = [&](int stop){
        cnt++;
        while(true){
            int cur = s.top();
            s.pop();
            in_stack[cur] = 0;
            cyc[cur] = cnt;
            if(cur == stop)break;
        }
    };
    function<void(int)> dfs = [&](int u){
        dis[u] = low[u] = ++timer;
        s.emplace(u);
        in_stack[u] = 1;
        for(int i: g[u]){
            if(dis[i] == 0){
                dfs(i);
                low[u] = min(low[i],low[u]);
            }
            else if(in_stack[i])
                low[u] = min(dis[i],low[u]);
        }
        if(dis[u] == low[u])popper(u);
    };
    for(int i = 1; i <= n; ++i)
        if(dis[i] == 0)dfs(i);
    vector<int> in(cnt+1);
    int index = 0;
    for(int i = 1; i <= n; ++i)
        for(int j: g[i])
            in[cyc[j]]+=(cyc[j] != cyc[i]);
    for(int i = 1; i <= cnt; ++i)
        if(index && in[i] == 0)return cout << "0\n",0;
        else if(in[i] == 0)index = i;
    vector<int> ans ;
    for(int i = 1; i <= n; ++i)
        if(cyc[i] == index)
            ans.emplace_back(i);
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(int i: ans)printf("%d ",i);
    return 0;
}