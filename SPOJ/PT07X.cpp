#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
int n,a,b,dp[N][2];

void dfs(int u, int p = -1){
	for(int i: g[u]){
		if(i == p)continue;
		dfs(i,u);
		dp[u][0] += dp[i][1];
		dp[u][1] += min(dp[i][0],dp[i][1]);
	}
	dp[u][1]++;
}

int main(){
	scanf("%d",&n);
	if(n == 1)return printf("1"),0;
	for(int i = 1; i < n; ++i){
		scanf("%d%d",&a,&b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1,-1);
//	for(int i = 1; i <= n; ++i)printf("dp[%d][0] = %d, dp[%d][1] = %d\n",i,dp[i][0],i,dp[i][1]);
	return printf("%d",min(dp[1][0],dp[1][1])),0;
}
