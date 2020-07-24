//https://codeforces.com/problemset/problem/118/D
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e8;
long long dp[101][101][2][11];
long long k1,k2;

long long cal(int n1, int n2, int type, int rem){
    if(n1 < 0 || n2 < 0)return 0;
    if(n1 == 0 && n2 == 0)return 1;
    long long &res = dp[n1][n2][type][rem];
    if(~res)return res;
    res = 0;
    if(rem != 0){
        if(type)res+=cal(n1,n2-1,type,rem-1);
        else res += cal(n1-1,n2,type,rem-1);
        res %= mod;
    }
    if(type)res+=cal(n1-1,n2,1-type,k1-1);
    else res += cal(n1,n2-1,1-type,k2-1);
    res %= mod;
    return res;
}

int main(){
    long long n1,n2;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp,-1,sizeof(dp));
    cout << (cal(n1-1,n2,0,k1-1)+cal(n1,n2-1,1,k2-1))%mod;
    return 0;
}