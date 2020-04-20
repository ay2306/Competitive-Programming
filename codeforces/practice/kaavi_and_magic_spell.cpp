//https://codeforces.com/contest/1337/problem/E
//Explanation: https://www.youtube.com/watch?v=FgrB_bvZJ_A&feature=youtu.be
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 998244353;
const int N = 3e3+10;

ll dp[N][N],ans,n,m;
char s[N],t[N];
int main(){
    scanf("%s%s",s+1,t+1);
    #ifdef DEBUG
        freopen("out","w",stdout);
    #endif
    n = strlen(s+1), m = strlen(t+1);
    for(int i = m; i <= n; ++i){
        if(i > m || s[i] == t[m])dp[i][0]=1;
        if(s[i] == t[1])dp[i][1] = 1;
    }
    for(int i = n; i > 1; i--){
        for(int j = 0; j <= n-i+1; ++j){
            if(j+1 > m || s[i-1] == t[j+1]){
                dp[i-1][j+1]=(dp[i-1][j+1]+dp[i][j])%mod;
            }
            if(i > 1){ // this condition so n-x does not become <= 0
                int x = n - i + 1 - j; // The filled 1s count
                if(n-x > m || s[i-1] == t[n-x]){
                    dp[i-1][j] = (dp[i-1][j]+dp[i][j])%mod;
                }
            }
        }
    }
    for(int i = 0; i <= n; ++i)ans = (ans+dp[1][i])%mod;
    return printf("%lld\n",ans),0;
}