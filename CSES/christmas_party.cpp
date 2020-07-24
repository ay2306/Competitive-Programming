#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7, N = 1e6+10;
int f[N];

int power(int a, int n){
	if( n == 0 ) return 1;
	if( n == 1 ) return a % mod;
	int p = power(a,n/2);
	p = p * p % mod;
	if ( n & 1 ) p = p * a % mod;
	return p;
}


int32_t main(){
	f[0] = 1;
	for(int i = 1; i < N; ++i){
	     f[i] = i * f[i-1];
	     if(f[i] >= mod)f[i] %= mod;	
	} 
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 2; i <= n; ++i){
		if(i & 1 ^ 1){
			ans += f[n] * power(f[i], mod - 2) % mod;
			if(ans >= mod)ans -= mod;
		}else{
			ans -= f[n] * power(f[i], mod - 2) % mod;
			if(ans < 0) ans += mod;
		}
	}
	cout << ans << "\n";
	return 0;
}
