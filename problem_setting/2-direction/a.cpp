#include<bits/stdc++.h>
using namespace std;

int main(){
	const int N = 1e5+1;
	int a,b,q,n,m,timer=0,cnt=0;
	scanf("%d%d",&n,&m);
	vector<int> g[N], cyc(n+1), in(n+1), low(n+1), dis(n+1), in_stack(n+1);
	while(m--){
		scanf("%d%d",&a,&b);
		g[a].emplace_back(b);
	}
	stack<int> s;
    auto popper = [&](int stop){
        cnt++;
        while(true){
            int cur = s.top();
            s.pop();
            in_stack[cur] = 0;
            cyc[cur] = cnt;
            if(cur == stop)break;
        }
    };
    function<void(int)> dfs = [&](int u){
        dis[u] = low[u] = ++timer;
        s.emplace(u);
        in_stack[u] = 1;
        for(int i: g[u]){
            if(dis[i] == 0){
                dfs(i);
                low[u] = min(low[i],low[u]);
            }
            else if(in_stack[i])
                low[u] = min(dis[i],low[u]);
        }
        if(dis[u] == low[u])popper(u);
    };
    for(int i = 1; i <= n; ++i)
        if(dis[i] == 0)dfs(i);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&a,&b);
		printf(cyc[a] == cyc[b] ? "yes\n" : "no\n");
	}
	return 0;
}


