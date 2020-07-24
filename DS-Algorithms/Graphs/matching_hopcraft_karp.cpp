#include<bits/stdc++.h>
using namespace std;
//Time complexity = O ( Elog(V) )
const int inf = 1e9;
struct Hopcraft_Karp{
	int n;
	vector<int> matchL, matchR, dist;
	vector<vector<int>> g;
	Hopcraft_Karp(int n):n(n),matchL(n+1),matchR(n+1),dist(n+1),g(n+1){}
	void addEdge(int u, int v){
		g[u].emplace_back(v);
	}
	bool bfs(){
		queue<int> q;
		for(int i = 1; i <= n; ++i){
			if(!matchL[i])
				dist[i] = 0,q.push(i);
			else dist[i] = inf;
		}
		dist[0] = inf;
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int v: g[u]){
				if(dist[matchR[v]] == inf)
					dist[matchR[v]] = dist[u] + 1,q.push(v);
			}
		}
		return dist[0] != inf;
	}
	bool dfs(int u){
		if(!u)return true;
		for(int v : g[u]){
			if(dist[matchR[v]] == dist[u]+1 && dfs(matchR[v])){
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
		dist[u] = inf;
		return false;
	}
	int matching(){
		int ans = 0;
		while(bfs()){
			for(int i = 1; i <= n; ++i)
				if(!matchL[i] && dfs(i))ans++;
		}
		return ans;
	}

};
