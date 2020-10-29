#include<bits/stdc++.h>
using namespace std;

int main(){
    const int N = 2e5+10; 
    set<int> g[N];
    int n,m,a,b;
    scanf("%d",&m);
    n = 2*m;
    vector<pair<int,int>> ans;
    while(m--){
        scanf("%d%d",&a,&b);
        g[a].emplace(b);
        g[b].emplace(a);
        ans.emplace_back(a,b);
    }
    for(int i = 1; i+1 <= n; i+=2){
        g[i].emplace(i+1);
        g[i+1].emplace(i);
    }
    vector<int> col(n+1,-1);
    function<bool(int,int)> dfs = [&](int u, int color)->bool{
        col[u] = color;
        for(int i: g[u]){
            if(col[i] == -1 && dfs(i,color^1) == false)return false;
            if(col[i] == color)return false;
        }
        return true;
    };
    for(int i = 1; i <= n; ++i){
        if(~col[i])continue;
        if(dfs(i,1) == false)return printf("-1"),0;
    }
    for(auto& [i,j]: ans)printf("%d %d\n",col[i]+1,col[j]+1);
    return 0;
}