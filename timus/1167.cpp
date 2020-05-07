#include<bits/stdc++.h>
const int N = 510,inf=1e9;

int dp[N][N],cost[N][N],a[N],n,k;

void dp_optimize(int part, int left, int right, int lo, int hi){
    if(left > right)return;
    int mid = left + right >> 1;
    dp[part][mid] = inf;
    int besti = lo;
    for(int i = lo; i <= std::min(hi,mid); ++i){
        int cst = dp[part-1][i-1] + cost[i][mid];
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

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i)scanf("%d",a+i);
    for(int i = 1; i <= n; ++i)a[i]+=a[i-1];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = inf,cost[i][j] = inf;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            int one = a[j]-a[i-1];
            int zero = (j-i+1)-one;
            cost[i][j] = one*zero;
        }
    }
    dp[0][0] = 0;
    for(int part = 1; part <= k; ++part)dp_optimize(part,1,n,1,n);
    return printf("%d\n",dp[k][n]),0;
}