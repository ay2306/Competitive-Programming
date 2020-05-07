//https://codeforces.com/contest/1256/problem/F
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

const int N = 1e5+10;
const ll mod = 1e9+7;
const ld pi = acos(-1.0);
const int inf = 1e9;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


ll parity(string &a){
    ord_set<P<char,int>> s;
    ll ans = 0;
    for(int i = a.size()-1; i >= 0; --i){
        ans+=s.order_of_key(mp(a[i],-inf));
        s.insert(mp(a[i],i));
    }
    return ans;
}

int solve(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    ll k1 = parity(a);
    ll k2 = parity(b);
    sort(all(a));
    sort(all(b));
    if(k1%2 != k2%2)for(int i = 1; i < n; ++i)if(a[i] == a[i-1])k1=k2;
    if(k2%2 == k1%2 && a==b){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}