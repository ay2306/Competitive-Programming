#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct Hopcraft_karp{
	int n;
	vector<int> matchL,matchR,dis;
	vector<vector<int>> g;
	Hopcraft_karp(int n):n(n),matchL(n+1),matchR(n+1),dis(n+1),g(n+1){}
	void add(int a, int b){
		g[a].emplace_back(b);
	}
	bool bfs(){
		queue<int> q;
		for(int i = 1; i <= n; ++i){
			if(!matchL[i])dis[i] = 0, q.emplace(i);
			else dis[i] = inf;
		}
		dis[0] = inf;
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int v : g[u]){
				if(dis[matchR[v]] == inf)
					dis[matchR[v]] = dis[u] + 1, q.emplace(matchR[v]);
			}
		}
		return dis[0] != inf;
	}
	bool dfs(int u){
		if(u == 0)return true;
		for(int v: g[u]){
			if(dis[matchR[v]] == dis[u]+1 && dfs(matchR[v])){
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
		dis[u] = inf;
		return false;
	}
	int matching(){
		int ans = 0;
		while(bfs()){
			for(int i = 1; i <= n; ++i){
				if(!matchL[i]){
					if(dfs(i))ans++;	
				}
			}
		}
		return ans;
	}
};

int main(){
	int n,m,p,a,b;
	scanf("%d%d%d",&n,&m,&p);
	Hopcraft_karp s(n+m);
	while(p--){
		scanf("%d%d",&a,&b);
		s.add(a,b+n);
	}
	return cout << s.matching() << "\n",0;
	return 0;
}
