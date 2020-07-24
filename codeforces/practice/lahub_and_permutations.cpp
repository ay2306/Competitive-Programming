//https://codeforces.com/contest/340/problem/E
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7,N = 2020;

int a,n,dp[N][N], arr[N];
set<int> s;

int factorial(int x){
    if(x <= 1)return 1;
    return x * factorial (x - 1) % mod;
}

int cal(int n, int k){
    int &res = dp[n][k];
    if(~res)return res;
    if(k == 0){
        res = factorial(n);
        return res;
    }
    else if(k == 1)res = n * cal(n,k-1) % mod;
    else res = (n * cal(n,k-1) % mod + (k-1) * cal(n+1,k-2) % mod) % mod;
    return res;
}

int32_t main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; ++i)s.emplace(i);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        if(~arr[i])s.erase(arr[i]);
    }
    n = s.size();
    int k = 0;
    for(const int i: s){
        if(~arr[i])continue;
        n--;
        k++;
    }
    cout << cal(n,k);
    return 0;
}