#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> g[N];
long double dis[N],ans;
int a,b,n;
void dfs(int s, int p = -1){
	p == -1 ? dis[s] = 1.0 : dis[s] = dis[p] + 1;
	for(int i : g[s])if(i != p)dfs(i,s);
}
int main(){
	scanf("%d",&n);
	for(int i = 1; i < n; ++i){
		scanf("%d%d",&a,&b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1);
	for(int i = 1; i <= n; ++i)ans += (1.0/dis[i]);
	printf("%.12Lf\n",ans);
	return 0;
}
