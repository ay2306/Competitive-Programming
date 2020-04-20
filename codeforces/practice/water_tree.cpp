//https://codeforces.com/problemset/problem/343/D
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll inf = 1e9+7;
const int N = 1e5+10;


vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
// *
// DEBUGGER



template<class T,size_t SZ>
struct segmentTree{
    T tree[SZ<<2],lazy[SZ<<2];
    segmentTree(){
        memset(tree,-1,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
    }
    void update(int l, int r, T val, int node = 1, int start = 0, int end = SZ-1){
        if(lazy[node]){
            tree[node] = lazy[node];
            if(start != end){
                lazy[node<<1] = lazy[node]; 
                lazy[node<<1|1] = lazy[node]; 
            }
            lazy[node] = 0;
        }
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            tree[node] = val;
            if(start != end){
                lazy[node<<1]   = val; 
                lazy[node<<1|1] = val; 
            }
            return ;
        }
        int mid = start+end >> 1;
        update(l,r,val,node<<1,start,mid);
        update(l,r,val,node<<1|1,mid+1,end);
        tree[node] = max(tree[node<<1] , tree[node<<1|1]);
    }
    T query(int l, int r, int node = 1, int start = 0, int end = SZ-1){
        if(lazy[node] != 0){
            tree[node] = lazy[node];
            if(start != end){
                lazy[node<<1] = lazy[node]; 
                lazy[node<<1|1] = lazy[node]; 
            }
            lazy[node] = 0;
        }
        if(l > end || r < start)return -2;
        if(l <= start && end <= r){
            return tree[node];
        }
        int mid = start+end >> 1;
        T p1 = query(l,r,node<<1,start,mid);
        T p2 = query(l,r,node<<1|1,mid+1,end);
        return max(p1,p2);
    }
};

template<size_t SZ, bool EDGE> 
struct HLD{
    int N,par[SZ],sz[SZ],depth[SZ];
    int root[SZ], pos[SZ];
    vector<int> g[SZ];
    void addEdge(int a, int b){
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    void dfsForSize(int v=1){
        // Here just delete parent and run dfs
        // and make bigchild the first child
        if(par[v])
            g[v].erase(find(g[v].begin(),g[v].end(),par[v]));
        sz[v] = 1;
        for(int &u: g[v]){
            par[u] = v;
            depth[u] = depth[v]+1;
            dfsForSize(u);
            sz[v]+=sz[u];
            if(sz[u] > sz[g[v][0]])swap(u,g[v][0]);
        }
    }
    void dfsHLD(int v=1){
        // what happens here is big child will have same 
        // root as this node 
        // other children will start new chain
        static int t = 0;
        pos[v] = t++;
        for(int &u: g[v]){
            root[u] = (u == g[v][0])?root[v]:u;
            dfsHLD(u);
        }
    }
    void init(int _N){
        N = _N;
        par[1] = depth[1] = 0;
        root[1] = 1;
        dfsForSize();
        dfsHLD();
    }
    template<class BinaryOp>
    void processPath(int u, int v, BinaryOp op){
        // till we reach last chain do this
        for(; root[u] != root[v]; v = par[root[v]]){
            if(depth[root[u]] > depth[root[v]])swap(u,v);
            op(pos[root[v]],pos[v]);
        }
        if(depth[root[u]] > depth[root[v]])swap(u,v);
        if(EDGE && u == v)return;
        op(min(pos[u],pos[v])+EDGE,max(pos[u],pos[v]));
    }
    segmentTree<int,SZ> tree;
    void modifyPath(int u, int v, int val){
        processPath(u,v,[this,&val](int l, int r){
            debug("Path",l,r,val);
            tree.update(l,r,val);
        });
    }
    void modifySubtree(int v,int val){
        tree.update(pos[v]+EDGE,pos[v]+sz[v]-1,val);
    }
    void modifyNode(int v, int val){
        tree.update(pos[v]+EDGE,pos[v]+EDGE,val);
    }
    int query(int u, int v){
        int res = 0;
        processPath(u,v,[this,&res](int l, int r){
            if(r < l)swap(r,l);
            debug("Query",l,r);
            res += tree.query(l,r);
        });
        return res;
    }
};

int main(){
    const int N = 5e5+100;
    HLD<N,false> hld;
    int n,a,b,c,d;
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        hld.addEdge(a,b);
    }    
    hld.init(N);
    scanf("%d",&n);
    while (n--){
        scanf("%d%d",&a,&b);
        debug(a,b);
        if(a == 1)hld.modifySubtree(b,1);
        if(a == 2)hld.modifyPath(b,1,-1);
        if(a == 3)printf("%d\n",hld.query(b,b) > 0);
    }
    return 0;
}