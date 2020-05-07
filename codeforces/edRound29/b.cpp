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

int solve()
{
    int n;
    cin >> n;
    V<ll> a(2*n);
    loop(i,0,2*n)cin >> a[i];
    ll ans = LLONG_MAX;
    loop(i,0,2*n){
        loop(j,i+1,2*n){
            V<ll> p;
            loop(k,0,2*n)if(i != k && j != k)p.pb(a[k]);
            sort(all(p));
            ll s = 0;
            loops(k,1,2*n-2,2){
                s+=p[k]-p[k-1];
            }
            ans = min(ans,s);
        }
    }
    cout << ans;
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