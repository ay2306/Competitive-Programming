//https://codeforces.com/contest/543/problem/A
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[2][600][600],mod,ans;
int n,lines,bugs,b[600];

int main(){
    scanf("%d%d%d%lld",&n,&lines,&bugs,&mod);
    for(int i = 1; i <= n; ++i)scanf("%d",b+i);
    dp[n&1^1][bugs][lines] = 1;
    for(int i = n; i >= 1; --i){
        for(int j = bugs; j >= 0; --j){
            for(int k = lines; k >= 0; --k){
                dp[i&1][j][k]=dp[i&1^1][j][k];
                if(j+b[n+1-i] <= bugs)
                    dp[i&1][j][k]=(dp[i&1][j][k]+dp[i&1][j+b[n+1-i]][k+1])%mod;
            }
        }
    }
    for(int i = 0; i <= bugs; ++i){
        ans += dp[1][i][0];
        ans %= mod;
    }
    printf("%lld",ans);
    return 0;
}