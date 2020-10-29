void pre_dfs(int v = 0){
    st[v] = dfs_time++;
    ver[ st[v] ] = v;
    sz[v] = 1, big[v] = -1;
    for(auto u : adj[v]){
        a[u] = (1 << s[u] - 'a') ^ a[v];
        h[u] = h[v] + 1;
        pre_dfs(u);
        sz[v] += sz[u];
        if(big[v] == -1 || sz[u] > sz[ big[v] ])
            big[v] = u;
    }
    ft[v] = dfs_time;
}
void dfs(int v = 0, bool cl = 0){
    for(auto u : adj[v])
	if(u != big[v])
	    dfs(u, 1), ans[v] = max(ans[v], ans[u]);
    if(big[v] != -1)
	dfs(big[v], 0), ans[v] = max(ans[v], ans[ big[v] ]);
    for(auto u : adj[v])
	if(u != big[v]){
	    for(int p = st[u]; p < ft[u]; p++){
		int x = ver[p];
		cur = max(cur, h[x] + bag[ a[x] ] - 2 * h[v]);
		for(int i = 0; i < z; i++)
		    cur = max(cur, h[x] + bag[ a[x] ^ (1 << i) ] - 2 * h[v]);
	    }
	    for(int p = st[u]; p < ft[u]; p++)
		bag[ a[ ver[p] ] ] = max(bag[ a[ ver[p] ] ], h[ ver[p] ]);
	}
    cur = max(cur, bag[ a[v] ] - h[v]);
    for(int i = 0; i < z; i++)
	cur = max(cur, bag[ a[v] ^ (1 << i) ] - h[v]);
    bag[ a[v] ] = max(bag[ a[v] ], h[v]);
    ans[v] = max(ans[v], cur);
    if(cl){
	for(int p = st[v]; p < ft[v]; p++)
	    bag[ a[ ver[p] ] ] = -inf;
	cur = 0;
    }
}