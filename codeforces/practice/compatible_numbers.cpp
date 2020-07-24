#include<bits/stdc++.h>
using namespace std;
const int N = (1 << 24), MB = 24, aux = (1 << MB) - 1;
int dp[N],n,a,arr[N];
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",arr+i);
        dp[(~arr[i])&aux] = arr[i];
    }
    for(int i = 0; i < MB; ++i){
        for(int j = 0; j < N; ++j){
            if(!((j >> i)&1))continue;
            if(~dp[j]){
                int nxt = j ^ (1 << i);
                dp[nxt] = dp[j];
            }
        }
    }
    for(int i = 0; i < n; ++i)printf("%d ",dp[arr[i]]);
    return 0;
}