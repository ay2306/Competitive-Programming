#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,z;
		scanf("%d%d%d",&n,&k,&z);
		vector<vector<vector<int>>> dp(n,vector<vector<int>>(z+3,vector<int>(2,-1)));
		vector<int> a(n);
		for(int &i: a)scanf("%d",&i);
		dp[0][z][0] = a[0];
		dp[0][z][1] = a[0];
		int ans = 0;
		int mvs = 0;
		while(~z){
			for(int i = 0; i < n; ++i){
				if(i && ~dp[i-1][z][0])dp[i][z][0] = max(dp[i][z][0],a[i]+dp[i-1][z][0]);
				if(i && ~dp[i-1][z][1])dp[i][z][0] = max(dp[i][z][0],a[i]+dp[i-1][z][1]);
				if(i+1 < n && ~dp[i+1][z+1][0])dp[i][z][1] = max(dp[i][z][1],a[i]+dp[i+1][z+1][0]);
				if(i+2*mvs == k)ans=max({ans,dp[i][z][0],dp[i][z][1]});
			}
			z--;
			mvs++;
		}
		printf("%d\n",ans);
	}
	return 0;
}