//https://codeforces.com/contest/137/problem/D
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n,k;
string s;
int p[510][510],dp[510][510],cost[510][510],opt[510][510];

int solve(int i, int k){
	if(i >= n)return 0;
	if(k == 1)return cost[i][n-1];
	if(~dp[i][k])return dp[i][k];
	dp[i][k] = inf;
	for(int len = n-i; len > 0; --len){
		int cst = solve(i+len,k-1) + cost[i][i+len-1];
		if(cst < dp[i][k])dp[i][k]=cst,opt[i][k]=len;
	}
	return dp[i][k];
}

int main(){
	cin >> s >> k;
	n = s.size();
	for(int i = 0; i < n; ++i){
		opt[i][1] = n-i;
		for(int j = i; j < n; ++j){
			for(int l = i, r = j; l <= r; l++,r--)cost[i][j]+=s[l]!=s[r];
		}
	}
	memset(dp,-1,sizeof(dp));
	solve(0,k);
	vector<string> ans;
	int mx = dp[0][k];
	if(k == 1)mx = cost[0][n-1];
	for(int i = 0; i < n; ){
		ans.emplace_back(s.substr(i,opt[i][k]));
		i += opt[i][k];
		k--;
	}
	for(auto &i: ans){
		for(int l = 0, r = i.size()-1; l < r; l++,r--)
			if(i[l] != i[r])i[r]=i[l];
	}
	cout << mx << "\n";
	for(int i = 0; i < ans.size(); ++i){
		if(i)cout << "+";
		cout << ans[i];
	}
	return 0;
}
