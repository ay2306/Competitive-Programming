//https://codeforces.com/problemset/problem/1304/E
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;
int a,b,c,x,y,k,n,q;
vector<int> g[N];
int dp[N][20],lev[N];

void dfs(int s = 1, int p = 0){
    dp[s][0] = p;
    for(int &i : g[s]){
        if(i==p)continue;
        lev[i] = lev[s] + 1;
        dfs(i,s);
    }
}

void pre(){
    for(int j = 1; j < 20; ++j){
        for(int i = 1; i <= n; ++i)dp[i][j] = dp[dp[i][j-1]][j-1];
    }
}

int lca(int a, int b){
    if(lev[a] > lev[b])swap(a,b);
    for(int i = 0; i < 20; ++i)if(((lev[b]-lev[a])>>i)&1)b=dp[b][i];
    if(a == b)return a;
    for(int i = 19; i >= 0; --i)if(dp[a][i] != dp[b][i])a=dp[a][i],b=dp[b][i];
    return dp[a][0];
}

int dist(int a, int b){
    return lev[a]+lev[b]-2*lev[lca(a,b)];
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs();
    pre();
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        int a1 = dist(a,b);
        int a2 = dist(a,x)+dist(y,b)+1;
        int a3 = dist(b,x)+dist(y,a)+1;
        if((a1 <= k && a1%2 == k%2) || (a2 <= k && a2%2 == k%2) || (a3 <= k && a3%2 == k%2))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}