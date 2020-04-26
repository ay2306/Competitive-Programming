#include<bits/stdc++.h>
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define F first
#define ll long long int
#define PLL pair<long long, long long>
#define P pair
#define PII pair<int,int>
#define V vector
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define S second
#define loopr(a,b,c) for(int a = b; a >= c; --a)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << " ";
#define debugn(x) cout << #x << " = " << x << "\n";
#endif
#ifndef LOCAL
#define debug(x)  34;
#define debugn(x) 34;
#endif
#define C continue
#define R return
using namespace std;
const ll mod = 1e9+7;
const int inf = 1e9;

ll power(ll a, ll n){
	if(n == 0)return 1;
	if(n == 1)return a%mod;
	ll p = power(a,n>>1);
	p*=p;
	p%=mod;
	if(n&1)p*=a;
	p%=mod;
	R p;
}

int solve(){
	int n;
	cin >> n;
	loop(i,0,100){
		if(i*3 <= n && (n-i*3)%7 == 0)R cout << "YES\n",0;
	}
	R cout << "NO\n",0;
}

int main(){
	fast
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}
