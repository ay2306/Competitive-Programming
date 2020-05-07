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
    string a;
    cin >> a;
    while(a.size() && a.back() == '0')a.pop_back();
    for(int i = 0, j = a.size()-1; i < j; ++i,j--)if(a[i]!=a[j])return cout << "NO\n",0;
    cout << "YES\n";
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