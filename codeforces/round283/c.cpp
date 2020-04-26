#include<bits/stdc++.h>
#define ll long long int
#define loop(a,b,c) for(int a = b; a < c; ++a);
#define loopr(a,b,c) for(int a = b; a >= c; --a);
#define P pair;
#define PII pair<int,int>
#define PLL pair<long long, long long>
#define V vector
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb emplace_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define ld long double
#define mod 1000000007
#ifndef LOCAL
#define deb(x) 45;
#endif 
#ifdef LOCAL
#define deb(x) cout << #x << " = " <<  x << "\n";
#endif 
using namespace std;
const int N = 1e5+10;
string a[110];
set<int> dem;
ll power(ll a, ll n){
    if(a >= mod)a%=mod;
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n>>1);
    if(p >= mod)p%=mod;
    if(n&1)p*=a;
    if(p >= mod)p%=mod;
    return p;
}


int solve(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)cin >> a[i];
    int cnt = 0,ans=0;
    V<PII> segments;
    segments.pb(0,n-1);
    for(int j = 0; j < m; ++j){
        deb(j);
        cnt = 0;
        for(auto &k: segments){
            deb(k.first);
            deb(k.second);
            for(int i = k.first; i+1 <= k.second; ++i){
                cnt+=(a[i+1][j] < a[i][j]);
            }
        }
        if(!cnt){
            V<PII> newSegments;
            for(auto &k: segments){
                int ui = k.first;
                int li = k.second;
                for(int i = k.first+1; i <= k.second; ++i){
                    if(a[i][j] != a[i-1][j]){
                        newSegments.pb(ui,i-1);
                        ui = i;
                    }
                }
                newSegments.pb(ui,li);     
            }
            segments = newSegments;
        }
        deb(cnt);
        ans+=(cnt > 0);
    }
    cout << ans << "\n";
    return 0;
}

int main(){
    fast
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}