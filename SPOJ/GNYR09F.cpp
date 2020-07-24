#include<bits/stdc++.h>
using namespace std;
const int N = 111;
long long dp[N][N][2];
int t,a,b,c;

int main(){
    dp[0][0][0] = 1;
    for(int i = 1; i < N; ++i){
        for(int j = 0; j < i; ++j){
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0];
            if(j)dp[i][j][1] += dp[i-1][j-1][1];
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        printf("%d %lld\n",a,dp[b][c][1]+dp[b][c][0]);
    }
    return 0;
}