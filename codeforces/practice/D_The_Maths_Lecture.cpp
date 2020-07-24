#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,mod,len;
int pw[1010],dp[1010][110][2],pwk[1010];
int cal(int pos, int rem, int val){
    if(val && rem == 0)return (pos != n) ? pw[n - pos - 1] * 9LL % mod : 1;
    if(pos == n)return 0;
    int &res = dp[pos][rem][val];
    if(~res)return res;
    res = 0;
    for(int i = 0; i <= 9; ++i){
        res += cal(pos+1, (rem + i * pwk[pos])%k, val || i);   
        if(res >= mod)res-=mod;
    }
    return res;
}

int32_t main(){
    cin >> n >> k >> mod;
    pw[0] = 1 % mod, pwk[0] = 1 % k;
    for(int i = 1; i <= 1010; ++i)pw[i] = pw[i-1]*10%mod;
    for(int i = 1; i <= 1010; ++i)pwk[i] = pwk[i-1]*10%k;
    memset(dp,-1,sizeof(dp));
    return cout << cal(0,0,0),0;
}