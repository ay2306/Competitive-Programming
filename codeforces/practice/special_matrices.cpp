#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
int n,m,mod;
int dp[N][N];
int one, zero;

int ncr(int n, int r){
    if(r < 0 || r > n)return 0;
    if(r == 1)return n;
    return (n * (n-1) / 2) % mod;
}

int cal(int i, int j){
    if(i+j > n || i < 0 || j < 0) return 0;
    if(~dp[i][j])return dp[i][j];
    dp[i][j] = 0;
    //To reach here we filled row with two zero columns
    dp[i][j] += ncr(i+2,2) * cal(i+2,j-2) % mod;
    //To reach here we filled row with 1 zero columns and 1 from 1 columns
    dp[i][j] += ncr(i+1,1) * ncr(j,1) % mod * cal(i+1,j) % mod;
    //To reach here we filled row with two one columns
    dp[i][j] += ncr(j+2,2) * cal(i,j+2) % mod;
    dp[i][j] %= mod;
    return dp[i][j];
}

signed main(){
    cin >> n >> m >> mod;
    vector<int> arr(n);
    string a;
    while(m--){
        cin >> a;
        for(int i = 0; i < n; ++i)arr[i]+=a[i]=='1';
    }
    memset(dp,-1,sizeof(dp));
    zero = n;
    for(int i: arr)one+=(i == 1),zero-=!!i;
    dp[zero][one] = 1;
    cout << cal(0,0) << "\n";
    return 0;
}