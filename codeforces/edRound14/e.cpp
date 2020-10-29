#include<bits/stdc++.h>
#define int __int128
#define vi vector<int> 
#define vvi vector<vector<int>>
using namespace std;
int mod = 1e9+7;
vvi m;
long long n,k;


void multiply(vvi &a, vvi b){
    vvi c(n,vi(n));
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            c[i][j] = 0;
            for(int K = 0; K < n; ++K){
                c[i][j] += a[i][K] * b[K][j] % mod;
                if(c[i][j] >= mod)c[i][j]-=mod;
            }
        }
    }
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            a[i][j] = c[i][j];
        }
    }
}


void power(vvi &a, int n){
    if(n == 0){
        for(int i = 0; i < a.size(); ++i)
            for(int j = 0; j < a.size(); ++j)a[i][j] = (i == j);
        return;
    }
    power(a,n/2);
    multiply(a,a);
    if(n&1)multiply(a,m);
}

void solve(){
    cin >> n >> k;
    m = vvi (n,vi(n));
    vvi res(n,vi(n));
    vector<long long> arr(n);
    for(auto &i: arr)cin >> i;
    if(k == 1)return void(cout << n);
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(__builtin_popcount(arr[i]^arr[j]) % 3 == 0)m[i][j] = 1,res[i][j] = 1;
        }
    }
    power(res,k-1);
    int ans = 0;
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            ans+=res[i][j];
            if(ans >= mod)ans-=mod;
        }
    }
    cout << (long long)ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}