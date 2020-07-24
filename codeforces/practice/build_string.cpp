//https://codeforces.com/contest/237/problem/E
// Code Reffered from Gepardo
#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;

struct MinCostMaxFlow{
	struct edge{
		int u,v,cost,cap,flow;
		edge(){}
		edge(int u, int v, int cost, int cap, int flow):
			u(u),v(v),cost(cost),cap(cap),flow(flow){}
	};
	int n,f,s,t;
	vector<edge> e;
	vector<vector<int>> g;
	vector<int> dis, p, pEdge, phi;
	void assignPriorities(){
		phi.assign(n,LLONG_MAX);
		phi[s] = 0;
		bool ok = true;
		while(ok){
			ok = false;
			for(auto i: e){
				if(phi[i.u] != LLONG_MAX && i.cap > i.flow){
					if(phi[i.v] > phi[i.u] + i.cost){
						phi[i.v] = phi[i.u] + i.cost;
					}
				}
			}
		}
	}
	bool djikstra(){
		priority_queue<PII,vector<PII>,greater<PII>> q;
		dis.assign(n,LLONG_MAX);
		p.assign(n,-1);
		pEdge.assign(n,-1);
		dis[s] = 0;
		p[s] = s;
		q.emplace(dis[s],s);
		while(q.size()){
			int d,u;
			tie(d,u) = q.top();
			q.pop();
			if(dis[u] != d)continue;
			for(auto id: g[u]){
				if(e[id].cap > e[id].flow){
					int v = e[id].v;
					int path = e[id].cost + phi[u] - phi[v];
					if(dis[v] > path + d){
						dis[v] = path + d;
						p[v] = u;
						pEdge[v] = id;
						q.emplace(dis[v],v);
					}	
				}
			}
		}
		return p[t] >= 0;
	}
	PII process(){
		// assignPriorities();
		phi.assign(n,0);
		int flow = 0, cost = 0;
		while(flow < f){
			if(!djikstra())break;
			for(int i = 0; i < n; ++i){
				if(p[i] >= 0)phi[i] += dis[i];
			}
			int add = f-flow;
			for(int v = t; v != s; v = p[v]){
				int id = pEdge[v];
				add = min(add,e[id].cap-e[id].flow);
			}
			flow+=add;
			for(int v = t; v != s; v = p[v]){
				int id = pEdge[v];
				cost += add * e[id].cost;
				e[id].flow += add;
				e[id ^ 1].flow -= add;
			}
		}
		return make_pair(flow,cost);
	}
	void addEdge(int u, int v, int cost, int cap){
		g[u].emplace_back(e.size());
		e.emplace_back(u,v,cost,cap,0);
		g[v].emplace_back(e.size());
		e.emplace_back(v,u,-cost,0,0);
	}
	MinCostMaxFlow(){}
	MinCostMaxFlow(int n, int f, int s, int t):
				n(n),f(f),s(s),t(t),g(n),dis(n),p(n),pEdge(n),phi(n){}
};

signed main() {
	string s; cin >> s;
	vector<int> must(26, 0);
	for (char c: s) {
		must[c - 'a']++;
	}
	int n; cin >> n;
	vector< vector<int> > v(n, vector<int>(26, 0));
	vector<int> f(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (char c: s) {
			v[i][c - 'a']++;
		}
		cin >> f[i];
	}
	const int src = 0;
	const int wordOffs = src + 1;
	const int letterOffs = wordOffs + n;
	const int dst = letterOffs + 26;
	const int cnt = dst + 1;
	MinCostMaxFlow mcmf(cnt, LLONG_MAX, src, dst);
	for (int i = 0; i < n; i++) {
		mcmf.addEdge(src, wordOffs + i, 0, f[i]);
		for (int j = 0; j < 26; j++) {
			mcmf.addEdge(wordOffs + i, letterOffs + j, i+1, v[i][j]);
		}
	}
	for (int i = 0; i < 26; i++) {
		mcmf.addEdge(letterOffs + i, dst, 0, must[i]);
	}
	int flow, cost; tie(flow, cost) = mcmf.process();
	if (flow == (int)s.size()) {
		cout << cost << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}