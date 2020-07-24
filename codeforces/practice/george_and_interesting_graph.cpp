#include<bits/stdc++.h>
using namespace std;
const int N = 1010,inf = 1e9;
vector<pair<int,int>> edges;
vector<int> g[N];
int matchL[N],matchR[N],dist[N];
int n,a,b,m,center,ans=INT_MAX;

bool bfs(){
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(!matchL[i])
			dist[i] = 0, q.emplace(i);
	       	else dist[i] = inf;	
	}
	dist[0] = inf;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int &v: g[u])
			if(dist[matchR[v]] == inf)
				dist[matchR[v]] = dist[u] + 1, q.emplace(v);
	}
	return dist[0] != inf;
}

bool dfs(int u){
	if(!u)return true;
	for(int &v: g[u]){
		if(dist[matchR[v]] == dist[u]+1 && dfs(matchR[v])){
			matchL[u] = v;
			matchR[v] = u;
			return true;
		}
	}
	dist[u] = inf;
	return false;
}

int GetMatching(){
	memset(matchL,0,sizeof(matchL));
	memset(matchR,0,sizeof(matchR));
	memset(dist,0,sizeof(dist));
	int match = 0;
	while(bfs()){
		for(int i = 1; i <= n; ++i){
			if(!matchL[i] && dfs(i))match++;
		}
	}
	return match;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; ++i){
		scanf("%d%d",&a,&b);
		edges.emplace_back(a,b);
	}
	for(center = 1; center <= n; ++center){
		int IN = n-1, OUT = n-1, self = 1, involved_edges = 0;
		for(int i = 1; i <= n; ++i)g[i].clear();
		for(auto& [u,v]: edges){
			if(u == center && u == v){
				self = 0;
				continue;
			}
			IN-=(u==center);
			OUT-=(v==center);
			if(u != center && v != center)g[u].emplace_back(v+n),involved_edges++;
		}	
		int matching = GetMatching();
		//Now there We expected n-1 matching to happen, so rest mathcing needs to be created
		int created = n - 1 - matching;
		//For involved edges - matching are the extra edges
		int extra = involved_edges - matching;
		//Now IN and OUT are left to be created along with self;
		int total = created + extra + IN + OUT + self;
		ans = min(ans, total);
		// printf("center = %d, IN = %d, OUT = %d, created = %d, extra = %d, invol = %d, matching = %d, ans = %d\n",center,IN,OUT,created,extra,involved_edges,matching,ans);
	}
	return printf("%d\n",ans),0;
}
