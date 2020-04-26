//https://codeforces.com/contest/780/problem/E
#include<bits/stdc++.h>
using namespace std;

int n,k,sz,a,b,m,vis[(int)3e5];
vector<int> g[(int)3e5],tree;

void dfs(int s = 1){
    tree.emplace_back(s);
    vis[s] = true;
    for(int &i: g[s]){
        if(vis[i])continue;
        dfs(i);
        tree.emplace_back(s);
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1);
    sz = 2*n/k + ((2*n)%k != 0);
    int j = 0;
    for(int i = 0; i < k ; ++i){
        int l = min(j,(int)tree.size()-1);
        int r = min(l + sz - 1,(int)tree.size()-1);
        j = r+1;
        printf("%d ",r-l+1);
        while(l <= r)printf("%d ",tree[l++]);
        printf("\n");
    }
    return 0;
}