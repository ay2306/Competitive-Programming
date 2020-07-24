//https://codeforces.com/contest/264/problem/C
#pragma GCC Optimize("O3")
#pragma GCC Optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+100;
int dp[N][3],n,q,a,b,val[N],c[N];
const int LMN = LLONG_MIN/100LL;
pair<int,int> mx,smx;
signed main(){
	scanf("%lld%lld",&n,&q);
	for(int i = 1; i <= n; ++i)cin >> val[i];
	for(int i = 1; i <= n; ++i)cin >> c[i];
	while(q--){
		scanf("%lld%lld",&a,&b);
		for(int i = 0; i < N; ++i)fill(dp[i],dp[i]+3,LMN);
		mx = pair<int,int> (LMN,LMN);
		smx = pair<int,int> (LMN,LMN);
		for(int i = 1; i <= n; ++i){
			dp[c[i]][1] = max(dp[c[i]][1],*max_element(dp[c[i]],dp[c[i]]+3) + val[i]*a);
			dp[c[i]][0] = max(dp[c[i]][0],val[i]*b);
			if(mx.first != c[i])dp[c[i]][2] = max(dp[c[i]][2],mx.second+val[i]*b);
			else dp[c[i]][2] = max(dp[c[i]][2],smx.second+val[i]*b);
			int m = *max_element(dp[c[i]],dp[c[i]]+3);
			if(m > mx.second && mx.first == c[i])mx.second = m;
			else if(m > mx.second){
				smx = mx;
				mx = make_pair(c[i],m);
			}
			else if(m > smx.second && smx.first == c[i])smx.second = m;
			else if(m > smx.second && mx.first != c[i])smx.second = m;
		}
		printf("%lld\n",max(0LL,mx.second));
	}
	return 0;
}
