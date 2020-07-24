#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct DINIC{
	struct edge{
		int u, v, flow, cap;
		edge(){}
		edge(int u, int v, int cap):u(u),v(v),cap(cap),flow(0LL){}
	};	
	vector<vector<int>> g;
	vector<edge> e;
	vector<int> p,pe,dis;
	int n, s, t, m;
	DINIC(){}
	DINIC(int n, int s, int t):n(n),s(s),t(t),g(n+1),p(n+1),pe(n+1),m(0LL),dis(n+1){}
	void add(int a, int b, int cap = 1){
		g[a].emplace_back(m++);
		g[b].emplace_back(m++);
		e.emplace_back(a,b,cap);
		e.emplace_back(b,a,0);
	}
	bool bfs(){
		dis.assign(n+1,-1);
		p.assign(n+1,-1);
		pe.assign(n+1,-1);
		queue<int> q;
		q.emplace(s);
		dis[s] = 0;
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int id: g[u]){
				if(e[id].cap <= e[id].flow || ~dis[e[id].v])continue;
				int v = e[id].v;
				p[v] = u;
				pe[v] = id;
				dis[v] = dis[u] + 1;
				q.emplace(v);
			}
		}
		return dis[t] >= 0;
	}
	int maxFlow(){
		int flow = 0;
		while(bfs()){
			int add = LLONG_MAX;
			for(int v = t; v != s; v = p[v]){
				add = min(add,e[pe[v]].cap - e[pe[v]].flow);
			}
			if(!add || add == LLONG_MAX)break;
			for(int v = t; v != s; v = p[v]){
				int id = pe[v];
				e[id].flow+=add;
				e[id^1].flow-=add;
			}
			flow+=add;
		}
		return flow;
	}
};

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int test = 1;
	while(true){
		int n;
		cin >> n;
		if(!n)break;
		int a,b,c,s, t, m;
		cin >> s >> t >> m;
		DINIC g(n,s,t);
		while(m--){
			cin >> a >> b >> c;
			if(a == t)swap(a,b);
			if(b == s)swap(a,b);
			if(a == t || b == s)g.add(a,b,c);
			else{
				g.add(a,b,c);
				g.add(b,a,c);
			}
		}
		cout << "Network " << test++ << "\n";
		cout << "The bandwidth is " << g.maxFlow() << ".\n\n";
	}
	return 0;
}
