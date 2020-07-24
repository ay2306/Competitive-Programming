//https://codeforces.com/contest/251/problem/C
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

int a,b,k;
int lev[360360+200];
int solve(int l, int r){
	if(l >= r)return 0;
	int n = r-l+1;
	memset(lev,-1,sizeof(lev));
	lev[n-1] = 0;
	queue<int> q;
	q.emplace(n-1);
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i = 2; i <= k; ++i){
			if((u+l)%i == 0)continue;
			int v = (u+l) - ((u+l) % i);
			// if(l <= v && v <= r)break;
			if(v <= 0)break;
			v -= l;
			if(lev[v] == -1){
				lev[v] = lev[u] + 1;
				q.emplace(v);
			}
		}
		int v = u-1;
		if(lev[v] == -1){
			lev[v] = lev[u] + 1;
			q.emplace(v);
		}
	}
	return lev[0];
}


signed main(){
	auto clk = std::chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> b >> a >> k;
	int lcm = 2;
	for(int i = 3; i <= k; ++i)lcm = lcm*i/__gcd(i,lcm);
	int ans = 0;
	int next_lcm = ((a+lcm-1)/lcm)*lcm;
	// return cout << lcm << "\n",0;
	if(next_lcm >= b)cout << solve(a,b) << "\n";
	else{
		int prev_lcm = b / lcm * lcm;
		int moves = prev_lcm/lcm - next_lcm/lcm;
		cout << solve(a,next_lcm) + moves * solve(lcm,lcm*2LL) + solve(prev_lcm , b) << "\n";
	}
	#ifdef LOCAL
		auto clk2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(clk2 - clk);
		cout << "\n\nTIME ELAPSED : " << time_span.count() * 1000.0 << " ms.\n"; 
	#endif
	return 0;
}
