#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g,dp;
vector<int> lev;
int n;

void dfs(int s = 1, int p = -1){
    if(p == -1)lev[s]=0;
    else lev[s]=lev[p]+1;
    dp[0][s] = p;
    for(auto &i: g[s]){
        if(i!=p)dfs(i,s);
    }
}

void pre(){
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; ++j){
            if(dp[i][j] != -1)dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
}

int lca(int a, int b){
    if(lev[a] > lev[b])swap(a,b);
    int diff = lev[b]-lev[a];
    for(int i = 0; i < 20; ++i)if((diff >> i)&1)b = dp[i][b];
    if(a == b)return a;
    for(int i = 19; i >= 0; --i){
        if(dp[i][a] != dp[i][b]){
            a=dp[i][a];
            b=dp[i][b];
        }
    }
    return dp[0][a];
}
void solve(){
    static int c = 1;
    scanf("%d",&n);
    g = vector<vector<int>> (n+12);
    dp = vector<vector<int>>(20,vector<int>(n+1,-1));
    lev = vector<int> (n+1);
    for(int i = 1; i <= n; ++i){
        int cnt,a,b;
        scanf("%d",&cnt);
        while(cnt--){
            scanf("%d",&a);
            g[a].emplace_back(i);
            g[i].emplace_back(a);
        }
    }
    dfs();
    pre();
    int q,a,b;
    scanf("%d",&q);
    printf("Case %d:\n",c++);
    while(q--){
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}