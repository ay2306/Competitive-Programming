#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+10, mod = 1e9+7;
int dp[N][N],n,m,k,pref[N];
signed main(){
	cin >> n >> m >> k;
	for(int i = 1; i < N; ++i)dp[i][0] = 1;
	for(int moves = 1; moves < N; ++moves){
		long long sum = 0;
		memset(pref,0,sizeof(pref));
		pref[0] = dp[0][moves-1];
		for(int i = 1; i < N; ++i)pref[i] = (pref[i-1] + dp[i][moves-1])%mod;
		for(int len = 3; len < N; ++len){
			dp[len][moves] = dp[len-1][moves]+pref[len-2];
			if(dp[len][moves] >= mod)dp[len][moves]-=mod;
		}
	}
	cout << dp[n][k] * dp[m][k] % mod << "\n";
	return 0;
}
