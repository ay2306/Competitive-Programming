#include<bits/stdc++.h>
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
	void addEdge(int a, int b, long long cap){
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
			while(long long push = dfs(s,LLONG_MAX)){
				ans += push;
				if(push == 0)return ans;
			}
		}
		return ans;
	}
};

int main(){
	function<int(char)> value = [](char i)->int{
		if(isupper(i))return i-'A'+26;
		return i-'a';
	};
	int n;
	cin >> n;
	DINIC flow(60,value('A'),value('Z'));
	while(n--){
		char a,b;
		long long int c;
		cin >> a >> b >> c;
		flow.addEdge(value(a),value(b),c);
	}
	return cout << flow.flow() , 0 ;
}