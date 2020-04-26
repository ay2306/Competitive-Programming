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
	int h1,h2,a1,a2,c1;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	V<string> ans;
	for(int i = 1; ; ++i){
		if(h2 - a1 <= 0){
			ans.emplace_back("STRIKE");
			break;
		}
		if(h1-a2 <= 0)ans.emplace_back("HEAL"),h1+=c1;
		else ans.emplace_back("STRIKE"),h2-=a1;
		h1-=a2;
	}
	cout << ans.size() << "\n";
	for(auto i: ans)cout << i << "\n";
	R 0;
}

int main(){
	fast
	int t = 1;
	// cin >> t;
	while(t--)solve();
	return 0;
}
