//https://codeforces.com/contest/1256/problem/E
#include<bits/stdc++.h>
#define ll long long int
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define P pair
#define PII pair<int,int>
#define PLL pair<long long, long long>
#define V vector
#define all(a) a.begin(),a.end()
#define pb emplace_back
#define mp make_pair
#define xx first
#define yy second
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a),0LL)
#define ld long double
#define C continue
#define R return
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << " ";
#define debugn(x) cout << #x << " = " << x << "\n";
#endif
#ifndef LOCAL
#define debug(x) 42;
#define debugn(x) 42;
#endif
using namespace std;

const ll inf = LLONG_MAX>>10;
const int N = 2e5+10;
const ll mod = 1e9+7;
const ld pi = acos(-1.0);


ll dp[N][6];

int solve(){
    int n;
    cin >> n;
    V<PLL> a(n+1) ;
    V<int> ans(n+1);
    loop(i,1,n+1)cin >> a[i].first,a[i].second = i;
    int mx = 0;
    int ex = n%3;
    sort(1+all(a));
    loop(i,0,N)loop(j,0,6)dp[i][j]=inf;
    dp[3][3] = a[3].first - a[1].first; 
    dp[4][4] = a[4].first - a[1].first; 
    dp[5][5] = a[5].first - a[1].first; 
    loop(i,6,n+1){
        loop(j,3,6){
            if(i-j < 0)break;
            loop(k,0,6){
                dp[i][j] = min(dp[i][j],dp[i-j][k] + a[i].first - a[i-j+1].first);
            }
        }
    }
    #ifdef LOCAL
    loop(i,1,n+1){
        debug(i);
        loop(j,0,6){
            if(dp[i][j] == inf)cout << "inf  ";
            else cout << dp[i][j] << "  ";
        }
        cout << "\n";
    }
    #endif
    int i = n;
    ll op = 0;
    int t = 1;
    while(i > 0){
        int bst = 0;
        loop(j,3,6){
            if(dp[i][j] < dp[i][bst]){
                bst = j;
            }
        }
        debugn(bst);
        op += a[i].first - a[i-bst+1].first;
        for(int j = 0; j < bst; ++j){
            ans[a[i].second] = t;
            i--;
        }
        t++;
    }
    cout << op << " " << t-1 << "\n";
    loop(i,1,n+1)cout << ans[i] << " ";
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}