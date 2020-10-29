#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,c,q;
    scanf("%d",&n);
    vector<vector<int>> g(n+1), dp(n+1, vector<int> (20,0));
    vector<int> lev(n+1,0);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    function<void(int,int)> dfs = [&](int s , int p)->void{
        for(int &i: g[s]){
            if(i == p)continue;
            dp[i][0] = s;
            lev[i] = lev[s] + 1;
            dfs(i,s);
        }
    };
    function<int(int, int)> findKth = [&](int a, int k){
        for(int i = 0; i < 20; ++i)if(k>>i&1)a=dp[a][i];
        return a;
    };
    function<int(int,int)> LCA = [&](int a, int b)->int{
        if(lev[a] > lev[b])swap(a,b);
        b = findKth(b, lev[b] - lev[a]);
        if(a == b)return a;
        for(int i = 19; ~i; --i)
            if(dp[a][i] != dp[b][i])
                a = dp[a][i], b = dp[b][i];
        return dp[a][0];
    };
    function<int(int,int)> distance = [&](int a, int b)->int{
        return lev[a] + lev[b] - 2 * lev[LCA(a,b)];
    };
    dfs(1,-1);
    for(int j = 1; j < 20; ++j)
        for(int i = 1; i <= n; ++i)
            dp[i][j] = dp[dp[i][j-1]][j-1];
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&a,&b,&c);
        int l = LCA(a,b);
        int la = distance(a,l);
        int lb = distance(b,l);
        if(lb + la <= c)printf("%d\n",b);
        else if(la >= c)printf("%d\n",findKth(a,c));
        else printf("%d\n",findKth(b,lb+la-c));
    }
    return 0;
}