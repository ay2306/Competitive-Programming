#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int SZ;
template<class T>
struct segmentTree{
    T *tree,*lazy;
	segmentTree(){
		tree = new int[SZ << 2];
		lazy = new int[SZ << 2];
        memset(sum,0,sizeof(sum));
        memset(lazy,0,sizeof(lazy));
    }
    void push(int node, int l, int r){
        sum[node]+=(r-l+1)*lazy[node];
        if(l != r)lazy[2*node]+=lazy[node],lazy[2*node+1]+=lazy[node];
        lazy[node] = 0;
    }
    void pull(int node, int l, int r){
        if(l!=r)sum[node] = sum[node*2]+sum[node*2 + 1];
    }
    void update(int l, int r, T val, int node = 1, int start = 0, int end = SZ-1){
        push(node,start,end);
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            lazy[node] = val;
            push(node,start,end);
            return;
        }
        int mid = start+end>>1;
        update(l,r,val,node*2,start,mid);
        update(l,r,val,node*2+1,mid+1,end);
        pull(node,start,end);
    }
    T query(int l, int r, int node = 1, int start = 0, int end = SZ-1){
        push(node,start,end);
        if(l > end || r < start)return 0;
        if(l <= start && end <= r){
            return sum[node];
        }
        int mid = start+end>>1;
        return query(l,r,node*2,start,mid) + query(l,r,node*2+1,mid+1,end);
    }
};

template<bool VALS_IN_EDGES> struct HLD{
    int N;
    vector<int> *g = new vector<int>[SZ];
    int *par = new int[SZ], *sz = new int[SZ], *depth = new int[SZ];
    int *root = new int[SZ], *pos = new int[SZ];
    void addEdge(int a, int b){g[a].emplace_back(b),g[b].emplace_back(a);}
    void dfsSz(int v = 1){
        if(par[v])g[v].erase(find(g[v].begin(),g[v].end(),par[v]));
        sz[v] = 1;
        for(int &u: g[v]){
            par[u]=v;
            depth[u] = depth[v]+1;
            dfsSz(u);
            sz[v]+=sz[u];
            if(sz[u] > sz[g[v][0]])swap(u,g[v][0]);
        }
    }
    void dfsHld(int v = 1){
        static int t = 0;
        pos[v] = t++;
        for(int &u: g[v]){
            root[u] = (u == g[v][0] ? root[v]:u);
            dfsHld(u);
        }
    }
    void init(int _N){
        N = _N;
        par[1] = depth[1] = 0;
        root[1] = 1;
        dfsSz();
        dfsHld();
    }
    template <class BinaryOp>
    void processPath(int u, int v, BinaryOp op){
        for(; root[u] != root[v]; v = par[root[v]]){
            if(depth[root[u]] > depth[root[v]])swap(u,v);
            op(pos[root[v]],pos[v]);
        }
        if(depth[root[u]] > depth[root[v]])swap(u,v);
        if(VALS_IN_EDGES && u == v)return;
        op(min(pos[u],pos[v])+VALS_IN_EDGES,max(pos[v],pos[u]));
    }
    segmentTree<int> tree;
    void modifyPath(int u, int v, ll val){
        processPath(u,v,[this,&val](int l, int r){
            tree.update(l,r,val);
        });
    }
    void modifySubtree(int v, ll val){
        tree.update(pos[v]+VALS_IN_EDGES,pos[v]+sz[v]-1,val);
    }
    void modifyNode(int v, ll val){
        tree.update(pos[v]+VALS_IN_EDGES,pos[v]+VALS_IN_EDGES,val);
    }
    ll queryPath(int u, int v){
        ll res = 0;
        processPath(u,v,[this,&res](int l, int r){
            if(r < l)swap(r,l);
            res=res+tree.query(l,r);
        });
        return res;
    }
};

int main(){
    int t;
	cin >> t;
	while(t--){
		
	}
	const int N = 100010;
    HLD<true> hld;
    V<PII> ed;
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i){int a,b;cin >> a >> b;hld.addEdge(a,b);ed.emplace_back(a,b);}
    hld.init(N);
    int k;
    cin >> k;
    while(k--){
        int a,b;
        cin >> a >> b;
        hld.modifyPath(a,b,1);
    }
    for(auto &i: ed)cout << hld.queryPath(i.F,i.S) << " ";
    return 0;
}