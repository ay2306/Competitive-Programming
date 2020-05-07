//https://codeforces.com/problemset/problem/321/E
#include<bits/stdc++.h>
const int N = 4010, inf = 1e9;
long long cost[N][N],g[N][N],n,dp[N][N],k,pref[N][N];


// Filling finding answer for jth parition
void divide_and_conquer_dp(int j, int L, int R, int lo, int hi){
    if(L>R)return;
    int mid = L+R>>1;
    int besti = 0;
    dp[j][mid] = inf;
    for(int i = lo; i <= std::min(hi,mid); ++i){
        // consider length i-mid for jth block
        long long cst = dp[j-1][i-1] + cost[i][mid];
        if(cst < dp[j][mid]){
            dp[j][mid] = cst;
            besti = i;
        }
    }
    if(L != R){
        divide_and_conquer_dp(j,L,mid-1,lo,besti);
        divide_and_conquer_dp(j,mid+1,R,besti,hi);
    }
}

int main(){
    scanf("%lld%lld",&n,&k);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char c = 'A';
            c = getchar();
            while(!isdigit(c))c=getchar();
            g[i][j] = c-'0';
            cost[i][j] = inf;
        }
    }
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            pref[i][j] += pref[i][j-1] + g[i][j],dp[i][j]=inf;
    
    for(int i = 1; i <= n; ++i){
        cost[i][i] = 0;
        for(int j = i+1; j <= n; ++j)
            cost[i][j] = cost[i][j-1]+pref[j][j]-pref[j][i-1];
    }
    dp[0][0] = 0;
    for(int j = 1; j <= k; ++j){
        // for(int i = 1; i <= n; ++i){
        //     for(int K = 1; K <= i; ++K){
        //         dp[j][i] = std::min(dp[j][i],dp[j-1][K-1]+cost[K][i]);
        //     }
        // }
        divide_and_conquer_dp(j,1,n,1,n);
    }
    #ifdef LOCAL
        printf("COST:\n");
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j)
                if(cost[i][j] != inf)printf("%5lld ",cost[i][j]);
                else printf("NA    ");
            printf("\n");
        }
        printf("dp:\n");
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j)
                printf("%lld ",dp[i][j]);
            printf("\n");
        }
    #endif
    return printf("%lld\n",dp[k][n]),0;
}