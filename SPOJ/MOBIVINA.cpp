#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
// #define int long long
using namespace std;

struct DINIC{
	struct Flow{
		int from, to;
		long long flow, cap;
		Flow(){}
		Flow(int u, int v, long long cap):from(u),to(v),flow(0),cap(cap){}
	};
	vector<int> level,ptr;
	vector<vector<int>> g;
	vector<Flow> edge;
	int n,m,s,t;
	queue<int> q;
	DINIC(int n, int s, int t):n(n),s(s),t(t){
		m = 0;
		g.resize(n);
		level.resize(n);
		ptr.resize(n);
	}
	void add(int a, int b, long long cap){
		edge.emplace_back(a,b,cap);
		edge.emplace_back(b,a,0);
		g[a].emplace_back(m);	
		g[b].emplace_back(m+1);
		m+=2;
	}
	bool bfs(){
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i : g[u]){
				auto it = edge[i];
				if(edge[i].cap-edge[i].flow < 1)continue;
				if(level[edge[i].to] != -1)continue;
				level[edge[i].to] = level[u] + 1;
				q.push(edge[i].to);
			}
		}
		return level[t] != -1;
	}
	long long dfs(int u, long long pushed){
		if(!pushed)return 0;
		if(u == t)return pushed;
		for(int &i = ptr[u]; i < (int)g[u].size(); ++i){
			int id = g[u][i];
			int v = edge[id].to;
			auto it = edge[id];
			if(level[v] != level[u]+1 || edge[id].cap-edge[id].flow < 1)continue;
			long long tr = dfs(v,min(pushed,edge[id].cap-edge[id].flow));
			if(tr == 0)continue;
			edge[id].flow+=tr;
			edge[id^1].flow -= tr;
			return tr;
		}
		return 0;
	}
	long long flow(){
		long long ans = 0;
		while(true){
			fill(level.begin(),level.end(),-1);
			level[s] = 0;
			q.push(s);
			if(!bfs())break;
			fill(ptr.begin(),ptr.end(),0);
			while(long long push = dfs(s,INT_MAX)){
				ans += push;
				if(push == 0)return ans;
			}
		}
		return ans;
	}
};

signed main(){
	int n,a;
	scanf("%d",&n);
	DINIC s(n+2,0,n+1);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&a);
		s.add(0,i,a);
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d",&a);
		s.add(i,n+1,a);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d",&a);
			s.add(i,j,a);
		}
	}
	printf("%d\n",s.flow());
	return 0;
}
