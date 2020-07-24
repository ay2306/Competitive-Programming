#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
vector<pair<int,int>> g[N];
vector<int> ans;
int dfs(int u, int p = -1, bool bad = false){
	int res = 0;
	for(auto& [v,t]: g[u])
		if(v!=p)res+=dfs(v,u,t==2);
	if(!res && (res == 0 && bad))ans.emplace_back(u);
	return res + (res == 0 && bad);
}

int main(){
	int n,a,b,c;
	cin >> n;
	for(int i = 0 ; i+1 < n; ++i){
		scanf("%d%d%d",&a,&b,&c);
		g[a].emplace_back(b,c);
		g[b].emplace_back(a,c);
	}
	dfs(1);
	printf("%d\n",(int)ans.size());
	for(int i: ans)printf("%d ",i);
	return 0;
}
