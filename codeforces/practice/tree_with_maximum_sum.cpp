//https://codeforces.com/contest/1092/problem/F
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5+10;

vector<vector<int>> g;
int n,A,B;
vector<ll> a,dp,asum;
ll ans;

void dfs(int s = 1, int p = 0, int level = 0){
    dp[s] = level*a[s];
    asum[s] = a[s];
    for(auto &i: g[s]){
        if(i != p){
            dfs(i,s,level+1);
            dp[s]+=dp[i];
            asum[s]+=asum[i];
        }
    }
}

void dfs2(int s = 1, int p = 0){
    ans = max(ans,dp[s]);
    for(auto &i: g[s]){
        if(i == p)continue;
          dp[s] -=   dp[i];
        asum[s] -= asum[i];

          dp[i] += (dp[s] + asum[s] - asum[i]);
        asum[i] += asum[s];

        dfs2(i,s);

        asum[i] -= asum[s];
          dp[i] -= (dp[s] + asum[s] - asum[i]);

          dp[s] +=   dp[i];
        asum[s] += asum[i];
    }
}



int main(){
    scanf("%d",&n);
    g.resize(n+1,vector<int>());
    a.resize(n+1);
    dp.resize(n+1,0LL);
    asum.resize(n+1,0LL);
    for(int i = 1; i <= n; ++i)scanf("%d",&a[i]);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&A,&B);
        g[A].emplace_back(B);
        g[B].emplace_back(A);
    }
    dfs();
    dfs2();
    printf("%lld\n",ans);
    return 0;
}