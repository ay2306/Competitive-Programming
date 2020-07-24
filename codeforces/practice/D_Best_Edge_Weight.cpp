#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct edge{
    int a,b,i,c,mst;
    edge(int a, int b, int c, int index):a(a),b(b),c(c),i(index),mst(0){}
    bool operator<(const edge &rhs)const{
        return c < rhs.c;
    }
    void print(){
        printf("a = %d, b = %d, index = %d mst = %d\n",a,b,i,mst);
    }
};

vector<edge> e;
vector<int> ans;

void mst_calculations(){
    int n,m,a,b,c,p[N],dp[N][20],mx[N][20],lev[N];
    vector<vector<edge>> g;
    memset(dp,0,sizeof(dp));
    memset(mx,0,sizeof(mx));
    memset(lev,0,sizeof(lev));
    scanf("%d%d",&n,&m);
    g = vector<vector<edge>> (n+1);
    ans = vector<int> (m);
    for(int i = 1; i <= n; ++i)p[i] = i;
    function<int(int)> findParent = [&](int x)->int{
        if(p[x] == x)return x;
        p[x] = findParent(p[x]);
        return p[x];
    };
    function<void(int,int)> join = [&](int a, int b)->void{
        p[findParent(a)] = p[findParent(b)];
    };
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d",&a,&b,&c);
        e.emplace_back(a,b,c,i);
    }
    sort(e.begin(),e.end());
    for(auto &i: e){
        if(findParent(i.a) != findParent(i.b)){
            join(i.a,i.b);
            i.mst = 1;
            g[i.a].emplace_back(i);
            g[i.b].emplace_back(i);
        }
    }
    sort(e.begin(),e.end(),[](const edge &a, const edge &b)->bool{
        return a.i < b.i;
    });
    function<void(int,int)> dfs = [&](int u, int parent = -1){
        for(auto &i: g[u]){
            int v = u ^ i.a ^ i.b;
            if(v != parent){
                lev[v] = lev[u] + 1;
                dp[v][0] = u;
                mx[v][0] = i.c;
                dfs(v,u);
            }
        }
    };
    dfs(1,-1);
    for(int j = 1; j < 20; ++j){
        for(int i = 1; i <= n; ++i){
            dp[i][j] = dp[dp[i][j-1]][j-1];
            mx[i][j] = max(mx[i][j-1],mx[dp[i][j-1]][j-1]);
        }
    }
    function<int(int,int)> maxPath = [&](int a, int b){
        if(lev[a] > lev[b])swap(a,b);
        int res = 0, diff = lev[b]-lev[a];
        for(int i = 0; i < 20; ++i)if((diff >> i) & 1)res=max(res,mx[b][i]),b=dp[b][i];
        if(a == b)return res;
        for(int i = 19; i >= 0; --i){
            if(dp[a][i] != dp[b][i]){
                res = max(res,mx[b][i]);
                res = max(res,mx[a][i]);
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        res = max(res,mx[b][0]);
        res = max(res,mx[a][0]);
        return res;
    };
    for(auto i: e){
        if(i.mst)continue;
        ans[i.i] = maxPath(i.a,i.b)-1;
    }
}

struct segmentTree{
    int tree[(N+10)<<2],lazy[(N+10)<<2];
    segmentTree(int init = INT_MAX){
    	fill(tree,tree+((N+10) << 2),init);
    	fill(lazy,lazy+((N+10) << 2),init);
    }
    void push(int node, int start, int end){
        tree[node] = min(tree[node],lazy[node]);
        if(start != end){
            lazy[node << 1] = min(lazy[node << 1], lazy[node]);
            lazy[node << 1 | 1] = min(lazy[node << 1 | 1], lazy[node]);
        }
        lazy[node] = INT_MAX;
    }
    void update(int l, int r, int val, int node = 1, int start = 0, int end = N){
        if(lazy[node] != INT_MAX)push(node,start,end);
        if(r < l || r < start || l > end)return;
        if(l <= start && end <= r){
            lazy[node] = min(lazy[node],val);
            push(node,start,end);
            return;
        }
        int mid = start + end >> 1;
        update(l,r,val,node << 1,start,mid);
        update(l,r,val,node<<1|1,mid+1,end);
        tree[node] = min(tree[node<<1],tree[node<<1|1]);
    }
    int query(int l, int r, int node = 1, int start = 0, int end = N){
        if(lazy[node])push(node,start,end);
        if(r < l || r < start || l > end)return INT_MAX;
        if(l <= start && end <= r)return tree[node];
        int mid = start + end >> 1;
        return min(query(l,r,node<<1,start,mid),query(l,r,node<<1|1,mid+1,end));
    }
};

template<bool EDGE>
struct hld{
    vector<int> g[N];
    int par[N],sz[N],depth[N];
    int root[N],pos[N];
    void add(int a, int b){
    	g[a].emplace_back(b);
    	g[b].emplace_back(a);
    }
    void dfsSz(int u = 1){
    	if(par[u])g[u].erase(find(g[u].begin(),g[u].end(),par[u]));
        sz[u] = 1;
        for(int &v: g[u]){
            par[v] = u;
            depth[v] = depth[u] + 1;
            dfsSz(v);
            sz[u]+=sz[v];
            if(sz[u] > sz[g[u][0]])swap(v,g[u][0]);
    	}
    }
    void dfsHld(int u = 1){
        // cout << u << "\n";
    	static int t = 1;
        pos[u] = t++;
        for(int v: g[u]){
            root[v] = g[u][0] == v ? root[u] : v;
            dfsHld(v);
        }
    }
    void init(int _N){
        par[1] = 0;
        depth[1] = 1;
        root[1] = 1;
        dfsSz();
        dfsHld();
    }
    template<class BinaryOp>
    void processPath(int u, int v, BinaryOp op){
    	for(; root[u] != root[v]; v = par[root[v]]){
		    if(depth[root[v]] < depth[root[u]])swap(u,v);
		    op(pos[root[v]],pos[v]);
	    }
        if(EDGE && u == v)return;
        int a = min(pos[u],pos[v]), b = max(pos[u],pos[v]);
        op(a+EDGE,b);
    }	    
    segmentTree tree;
    void modifyPath(int u, int v, int val){
    	processPath(u,v,[this,&val](int l, int r){
            tree.update(l,r,val);
        });
    }
    int queryPath(int u, int v){
    	int res = INT_MAX;
        processPath(u,v,[this,&res](int l, int r){
            if(r < l)swap(r,l);
            int val = tree.query(l,r);
            res = res > val ? val : res;
        });
        return res;
    }
};

int main(){
    mst_calculations();
    hld<true> s;
    for(auto &i: e){
        if(!i.mst)continue;
        s.add(i.a,i.b);
    }
    s.init(100);
    for(auto &i: e){
        if(i.mst)continue;
        s.modifyPath(i.a,i.b,i.c);
    }
    for(auto &i: e){
        if(!i.mst)continue;
        ans[i.i] = s.queryPath(i.a,i.b);
        if(ans[i.i] == INT_MAX)ans[i.i] = 0;
        ans[i.i]--;
    }
    for(auto i: ans)cout << i << " ";
    return 0;
}