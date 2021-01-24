#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	cin >> n;
	vector<vector<int>> g(n+1);
	vector<int> arr(n+1);
	for(int i = 1; i <= n; ++i)cin >> arr[i];
	for(int i = 1; i < n; ++i){
		int a,b;
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	int mn = LLONG_MAX;
	vector<int> ans, sub(n+1), sum(n+1);
	int total = accumulate(arr.begin(),arr.end(),0LL);
	function<void(int,int)> dfs = [&](int s, int p){
		sub[s] = 1;
		sum[s] = arr[s];
		int town = 0;
		for(int i: g[s]){
			if(i == p)continue;
			dfs(i,s);
			town += sub[i] * sum[i];
			sub[s] += sub[i];
			sum[s] += sum[i];
		}
		town += (n-sub[s])*(total-sum[s]);
		if(town < mn){
			mn = town;
			ans.clear();
		}
		if(mn == town){
			ans.emplace_back(s);
		}
	};
	dfs(1,-1);
	sort(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(int i: ans)cout << i << " ";
	return 0;
}
