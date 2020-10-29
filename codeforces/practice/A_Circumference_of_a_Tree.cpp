#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
vector<int> g[N];
int n,a,b,level[N] = {-1};
int dfs(int s, int p = 0){
    level[s] = level[p] + 1;
    int mx = s;
    for(int i : g[s]){
        if(i == p)continue;
        int res = dfs(i,s);
        if(level[res] > level[mx])mx = res;
    }
    return mx;
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans = level[dfs(dfs(1))];
    printf("%d",3*ans);
    return 0;
}