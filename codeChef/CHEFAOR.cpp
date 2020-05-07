#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
const ll N = 5010, inf = 1e15;
int n,k;
ll dp[N][N],a[N],cost[N][N];

void dp_optimize(int part, int left, int right, int lo, int hi){
    if(left > right)return;
    int mid = left + right >> 1;
    int besti = lo;
    dp[part][mid] = inf;
    for(int i = lo; i <= std::min(mid,hi); ++i){
        ll cst = dp[part-1][i-1] - cost[i][mid];
        if(cst < dp[part][mid]){
            dp[part][mid] = cst;
            besti = i;
        }
    }
    if(left != right){
        dp_optimize(part,left,mid-1,lo,besti);
        dp_optimize(part,mid+1,right,besti,hi);
    }
}

void solve(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i)scanf("%d",a+i);
    for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= n; ++j)dp[i][j] = inf,cost[i][j] = inf;
    for(int i = 1; i <= n; ++i){
        cost[i][i] = a[i];
        for(int j = i+1; j <= n; ++j)cost[i][j] = cost[i][j-1]|a[j];
    }
    dp[0][0] = 0;
    for(int part = 1; part <= k; ++part)dp_optimize(part,1,n,1,n);
    printf("%lld\n",-dp[k][n]);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}