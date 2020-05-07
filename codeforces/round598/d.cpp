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
#define debugn(x) cout << #x << " = " << x << "\n";
#endif
using namespace std;

const int N = 1e5+10;
const ll mod = 1e9+7;
const ld pi = acos(-1.0);


int solve(){
    ll n,m,des = 0;
    cin >> n >> m;
    string a;
    cin >> a;
    for(int i = 0; i < n; ++i){
        if(a[i] == '1') continue;
        if(i-des > m){
            swap(a[i],a[i-m]);
            break;
        }else{
            m-=(i-des);
            swap(a[i],a[des]);
            des++;
        }
    }
    cout << a << "\n";
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