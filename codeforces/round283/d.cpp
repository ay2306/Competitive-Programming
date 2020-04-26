//https://codeforces.com/contest/496/problem/D
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
using namespace std;
const int N = 1e5+10;
const int inf = 1e8;

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
    int n;
    cin >> n;
    set<PII> k;
    V<int> p1,p2,a(n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    if(a[n-1] == 2){
        for(int i = 0; i < n; ++i)a[i] = 3-a[i];
    }
    for(int i = 0; i < n; ++i)if(a[i] == 1)p1.pb(i);else p2.pb(i);
    for(int t = 1; t <= n; ++t){
        int w = 0, l = 0,poss = 0,s=0;
        for(int pos = 0; pos < n;){
            int d1 = inf, d2 = inf;
            int P1 = lower_bound(all(p1),pos) - p1.begin();
            int P2 = lower_bound(all(p2),pos) - p2.begin();
            P1+=t-1;
            P2+=t-1;
            if(P1 >= p1.size())break;
            if(P2 < p2.size())d2 = p2[P2];
            d1 = p1[P1];
            if(d1 < d2)w++,pos=d1+1;
            else l++,pos=d2+1;
            if(d1 == inf)d1 = -1;
            if(d2 == inf)d2 = -1;
            if(pos == n)poss = 1;
            s++;
        }
        if(w > l && poss)k.insert(mp(w,t));
    }
    cout << k.size() << "\n";
    for(auto &i: k)cout << i.first << " " << i.second << "\n";
    return 0;
}

int main(){
    fast
    int t=1;
    // cin >> t;
    while(t--)solve();
    return 0;
}