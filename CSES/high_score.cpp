#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2600;
struct edge{
	int a, b, c;
	edge(int a, int b, int c):a(a),b(b),c(c){}
};
vector<edge> e;
vector<int> g[N];
int dis1[N],dis2[N],n,m,a,b,c;
bool vis[N][N];
void bellman_ford(int source , int RUNNER, int *dis){
	fill(dis,dis+N,LLONG_MAX);
	dis[source] = 0;
	for(int i = 0; i < RUNNER; ++i){
		for(edge &ed: e){
			if(dis[ed.a] < LLONG_MAX){
				dis[ed.b] = min(dis[ed.b],dis[ed.a]+ed.c);
			}
		}
	}
}

void dfs(int s, int src){
	vis[src][s] = true;
	if(s == n)return;
	for(int i : g[s]){
		if(!vis[src][i])dfs(i,src);
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		cin >> a >> b >> c;
		e.emplace_back(a,b,-c);
		g[a].emplace_back(b);
	}
	bellman_ford(1,n,dis1);
	bellman_ford(1,2*n,dis2);
	for(int i = 1; i <= n; ++i)dfs(i,i);
	for(int i = 1; i <= n; ++i){
		if(dis1[i] != dis2[i] && vis[1][i] && vis[i][n]){
			return cout << -1,0;
		}
	}
	return cout << -dis1[n],0;
}
