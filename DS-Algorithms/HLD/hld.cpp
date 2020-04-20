#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll inf = 1e9+7;
const int N = 1e5+10;

template<class T, int SZ>
struct segmentTree{
    T sum[SZ<<2], lazy[SZ<<2];
    segmentTree(){
        memset(sum,0,sizeof(sum));
        memset(lazy,0,sizeof(lazy));
    }
    void push(int node, int l, int r){
        sum[node]+=lazy[node];
        if(l != r)lazy[2*node]+=lazy[node],lazy[2*node+1]+=lazy[node];
        lazy[node] = 0;
    }
    void pull(int node, int l, int r){
        if(l!=r)sum[node] = __gcd(sum[node*2],sum[node*2 + 1]);
    }
    void update(int l, int r, T val, int node = 1, int start = 0, int end = SZ-1){
        push(node,start,end);
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            sum[node] = val;
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
        if(l > end || r < start)return INT_MIN;
        if(l <= start && end <= r){
            return sum[node];
        }
        int mid = start+end>>1;
        return max(query(l,r,node*2,start,mid) , query(l,r,node*2+1,mid+1,end));
    }
};

template<int SZ, bool VALS_IN_EDGES> struct HLD{
    int N;
    vector<int> g[SZ];
    int par[SZ], sz[SZ], depth[SZ];
    int root[SZ], pos[SZ];
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
    segmentTree<ll,SZ> tree;
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
        ll res = INT_MIN;
        processPath(u,v,[this,&res](int l, int r){
            if(r < l)swap(r,l);
            res=max(res,tree.query(l,r));
        });
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    const int N = 100010;
    HLD<N,false> hld;
    for(int i = 1; i < n; ++i){int a,b;cin >> a >> b;hld.addEdge(a,b);}
    hld.init(N);
    int q;
    cin >> q;
    return 0;
}
