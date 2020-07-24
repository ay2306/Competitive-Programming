#include<bits/stdc++.h>
using namespace std;

struct MinCostMaxFlow{
	struct edge{
		int u,v;
		long long flow,cap,cost;
		edge(){}
		edge(int u, int v, long long cap, long long cost):u(u),v(v),cap(cap),flow(0),cost(cost){}
	};
	vector<edge> e;
	vector<vector<int>> g;
	vector<int> dist,ptr,parent;
	int n,m,s,t;
	long long minCost,maxFlow;
	MinCostMaxFlow(){}
	MinCostMaxFlow(int n, int m, int s, int t):n(n),m(0),s(s),t(t),g(n+1),dist(n+1),ptr(n+1),parent(n+1){}
	void add(int a, int b, long long cap, long long cost){
		e.emplace_back(a,b,cap,cost);
		e.emplace_back(b,a,0,-cost);
		g[a].emplace_back(m);
		g[b].emplace_back(m+1);
		m+=2;
	}
	bool bellman_ford(){
		fill(dist.begin(),dist.end(),LLONG_MAX);
		fill(parent.begin(),parent.end(),-1);
		dist[s] = 0;
		for(int iterator = 1; iterator < n; ++iterator){
			for(auto i: e){
				if(dist[i.u] == LLONG_MAX || i.cap-i.flow < 1)continue;
				dist[i.v] = min(dist[i.v],dist[i.v]+i.cost);
			}
		}
		return dist[t] != LLONG_MAX;
	}
	long long dfs(int u, long long pushed = LLONG_MAX){
		if(u == t)return pushed;
		if(pushed == 0)return 0;
		for(int &point = ptr[u]; point < (int)g[u].size(); point++){
			int id = g[u][point];
			int v = e[id].v;
			if(parent[v] != u || e[id].cap-e[id].flow < 1)continue;
			long long res = dfs(v,min(pushed,ed[id].cap-e[id].flow));
			if(res == 0)continue;
			minCost += res * e[id].cost;
			e[id].flow+=res;
			ed[id^1].flow-=res;
			return res;
		}
		return 0;
	}
	void process(){
		minCost = 0;
		maxFlow = 0;
		while(bellman_ford()){
			for(;long long pushed = dfs(s,LLONG_MAX););
		}
	}
};

int main(){

	return 0;
}
