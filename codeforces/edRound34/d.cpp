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
const int N = 2e5+10;
int solve(){
	int n,t=0;
	cin >> n;
	map<ll,ll> m,f;
	V<__int128> arr(n);
	__int128 ans = 0;
	ll k;
	for(ll i = 0; i < n; ++i){cin >> k;arr[i]=k;}
	for(ll i = 0; i < n; ++i)m[arr[i]]++;
	for(ll i = 0; i < n; ++i){
		__int128 total = n;
		__int128 left = i;
		__int128 right = n-i-1;
		if(f.count(arr[i]))left -= f[arr[i]];
		if(f.count(arr[i]-1))left -= f[arr[i]-1]; 
		if(f.count(arr[i]+1))left -= f[arr[i]+1]; 
		f[arr[i]]++;
		if(m.count(arr[i]))right -= (m[arr[i]] - f[arr[i]]);
		if(m.count(arr[i]+1))right -= (m[arr[i]+1] - f[arr[i]+1]);
		if(m.count(arr[i]-1))right -= (m[arr[i]-1] - f[arr[i]-1]);
		ans = ans + ((left-right)*1LL*arr[i]);
		debug(left);
		debug(arr[i]);
		debug(arr[i]*left);
		debug(right);
		debug(arr[i]*right);
		debugn(ans);
	}
	std::cout << (long long)ans << "\n";
	R 0;
}

int main(){
	fast
	int t = 1;
	// cin >> t;
	while(t--)solve();
	return 0;
}