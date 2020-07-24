#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n,x;
int coin[110];
int dp[1000001];

int main(){
    scanf("%d%d",&n,&x);
    for(int i = 0; i < n; ++i){
        scanf("%d",coin+i);
    }
    sort(coin,coin+n);
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int c = 1; c <= x; ++c){
        for(int i = 0; i < n; ++i){
            if(coin[i] > c)break;
            dp[c] += dp[c-coin[i]];
            if(dp[c] >= mod)dp[c]-=mod;
        }
    }
    return printf("%d",dp[x]),0;
}