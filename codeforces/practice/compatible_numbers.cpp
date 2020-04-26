//https://codeforces.com/contest/165/problem/E
#include<bits/stdc++.h>
using namespace std;
const int B = 22, MB = (1 << 22);
int n,a[MB],dp[MB];
int main(){
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < n; ++i){
        scanf("%d",a+i);
        dp[a[i]] = a[i];
    }
    for(int i = 0; i < B; ++i){
        for(int j = 0; j < MB; ++j){
            if(~dp[j])dp[j|(1<<i)] = dp[j];
        }
    }
    for(int i = 0 ; i < n; ++i)printf("%d ",dp[~a[i]&MB-1]);
    return 0;
}