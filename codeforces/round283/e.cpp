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

    return 0;
}

int main(){
    fast
    int t;
    // cin >> t;
    while(t--)solve();
    return 0;
}