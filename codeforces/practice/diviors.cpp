//https://codeforces.com/contest/448/problem/E
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int LIM = 1e5;
vector<int> DIV,ans;
unordered_map<int,vector<int>> factors;
int n,k;

void dfs(int x, int ks){
	if(ans.size() == LIM)return;
	if(ks == 0 || x == 1)ans.emplace_back(x);
	else{
		for(auto i: factors[x])dfs(i,ks-1);
	}
}

signed main(){
	scanf("%lld %lld",&n,&k);
	for(int i = 1; i * i <= n; ++i){
		if(n%i)continue;
		DIV.emplace_back(i);
		if(i*i != n)DIV.emplace_back(n/i);
	}
	sort(DIV.begin(),DIV.end());
	for(int i: DIV){
		for(int j: DIV){
			if(j > i)break;
			if(i % j == 0)factors[i].emplace_back(j);
		}
	}
	dfs(n,k);
	for(int i: ans)printf("%lld ",i);
	return 0;
}
