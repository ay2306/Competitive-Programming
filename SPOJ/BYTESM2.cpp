#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;

ll arr[150][150];
ll dp[150][150];
void solve(){
    int n,m;
    cin >> n >> m;
    loop(i,0,n){
        loop(j,0,m)cin >> arr[i][j];
    }
    loop(i,0,n)dp[0][i] = arr[0][i];
    loop(i,1,n){
        loop(j,0,m){
            ll a = 0, b = 0, c = 0;
            if(j-1 >= 0)a=dp[i-1][j-1];
            b = dp[i-1][j];
            if(j+1 < m)c = dp[i-1][j+1];
            dp[i][j] = arr[i][j] + max(a,max(b,c));
        }
    }
    ll mx = 0;
    for(int i = 0; i < m; ++i){
        mx = max(mx,dp[n-1][i]);
    }
    cout << mx << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
   return 0;
}