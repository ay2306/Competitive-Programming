#include<bits/stdc++.h>
#define int long long
#define vi vector<int> 
#define vvi vector<vector<int>>
using namespace std;
int mod = 1e9+7;
vvi m;
int n,k;


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
    if(n < 2)return;
    power(a,n/2);
    multiply(a,a);
    if(n&1)multiply(a,m);
}

void solve(){
    cin >> n >> k;
    m = vvi (n,vi(n));
    vvi res(n,vi(n));
    vi arr(n);
    for(auto &i: arr)cin >> i;
    if(k == 1)return void(cout << n);
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int val = arr[i] ^ arr[j];
            int cnt = 0;
            while(val){
                cnt+=(val&1);
                val/=2;
            }
            m[i][j] = (cnt % 3 == 0);
            res[i][j] = (cnt % 3 == 0);
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
    cout << ans;
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