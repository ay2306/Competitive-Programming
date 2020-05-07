//https://codeforces.com/contest/863/problem/C
/************************
 *                      *
 *    Author: ay2306    *
 *                      *
 ************************
*/

#include <bits/stdc++.h>
#define ll long long int
#define all(a) a.begin(), a.end()
#define loop(a, b, c) for (int a = b; a < c; ++a)
#define V vector
#define P pair
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define ld long double
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define SUM(a) accumulate(all(a), 0LL)
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));
#define loops(a, b, c, d) for (int a = b; a < c; a += d)
#define loopr(a, b, c) for (int a = b; a >= c; a--)
#define looprs(a, b, c, d) for (int a = b; a >= c; a -= d)
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << " ";
#define debugn(x) cout << #x << " = " << x << "\n";
#endif
#define R return
#define C continue
#ifndef LOCAL
#define debug(x) 24;
#define debugn(x) 24;
#endif
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld pi = acos(-1.0);

map<PII,V<P<P<ll,ll>,PII>>> g;
map<PII,ll> sum[10000];
map<PII,ll> draw[10000];
map<PII,PII> dp[10000];
map<PII,bool> vis;
int dfscnt = 0 ;

void dfs(PLL s, PLL p = mp(0,0)){
    // if(dfscnt > 100000){
    //     cout << "DFS ISSUE\n";
    //     return;
    // }
    if(vis.count(s))return;
    vis[s] = 1;
    for(auto &i: g[s]){
        dp[0][s] = i.S; 
        sum[0][s] = i.F.F;
        draw[0][s] = i.F.S;
        dfs(i.S);
    }
}

int solve()
{
    ll kcopy,acopy,bcopy;
    ll K,a,b;
    cin >> K >> a >> b;
    kcopy = K;
    acopy = a;
    bcopy = b;
    ll A[5][5], B[5][5];
    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            cin >> B[i][j];
        }
    }
    a = acopy;
    K = kcopy;
    b = bcopy;
    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            ll p = 0;
            ll q = 0;
            if(i == 1 && j == 3)p++;
            if(i == 2 && j == 1)p++;
            if(i == 3 && j == 2)p++;
            if(j == 1 && i == 3)q++;
            if(j == 2 && i == 1)q++;
            if(j == 3 && i == 2)q++;
            g[{i,j}].pb(mp(mp(p,q),mp(A[i][j],B[i][j])));     
        }
    }
    loop(i,1,4)loop(j,1,4)if(!vis.count(mp(i,j)))dfs(mp(i,j));
    int bit = 0;
    for(int j = 1; K >= (1LL << j); ++j){
        loop(i1,1,4){
            loop(j1,1,4){
                PLL i = mp(i1,j1);
                dp[j][i] = dp[j-1][dp[j-1][i]];
                sum[j][i] = sum[j-1][i] + sum[j-1][dp[j-1][i]];
                draw[j][i] = draw[j-1][i] + draw[j-1][dp[j-1][i]];
            }
        }
    }
    ll ans1 = 0, ans2 = 0;
    K = kcopy;
    PII cur = mp(a,b);
    int i = 0;
    while(K >= (1LL << i)){
        if((K >> i)&1){
            ans1+=sum[i][cur];
            ans2+=draw[i][cur];
            cur = dp[i][cur];
        }
        i++;
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}