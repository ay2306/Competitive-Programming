#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
typedef long long int ll;
const ll inf = 1e9+7;
const int N = 1e5+10;

int pr[N];

ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n>>1);
    p*=p;
    if(p >= inf)p%=inf;
    if(n&1){
        p*=a;
        if(p >= inf)p%=inf;
    }
    return p;
}

void pre(){
    for(int i = 2; i < N; ++i){
        if(pr[i] == 0){
            for(int j = i; j < N; j+=i)pr[j]=i;
        }
    }
}

ll Ans(ll g){
    unordered_map<int,int> m;
    if(g==1)return -1;
    while(g > 1){
        m[pr[g]]++;
        g/=pr[g];
    }
    ll num = m.size();
    ll denom = 1;
    for(auto &i: m)denom*=(i.second+1);
    denom--;
    return (num*power(denom,inf-2))%inf;
}

template<class T, int SZ>
struct segmentTree{
    T sum[SZ<<2];
    segmentTree(){
        memset(sum,0,sizeof(sum));
    }
    void pull(int node, int l, int r){
        if(l!=r)sum[node] = __gcd(sum[node*2],sum[node*2 + 1]);
    }
    void update(int l, int r, T val, int node = 1, int start = 0, int end = SZ-1){
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            sum[node] = val;
            return;
        }
        int mid = start+end>>1;
        update(l,r,val,node*2,start,mid);
        update(l,r,val,node*2+1,mid+1,end);
        pull(node,start,end);
    }
    T query(int l, int r, int node = 1, int start = 0, int end = SZ-1){
        if(l > end || r < start)return 0;
        if(l <= start && end <= r){
            return sum[node];
        }
        int mid = start+end>>1;
        return __gcd(query(l,r,node*2,start,mid) , query(l,r,node*2+1,mid+1,end));
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
        op(pos[u]+VALS_IN_EDGES,pos[v]);
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
        ll res = 0;
        processPath(u,v,[this,&res](int l, int r){
            if(r < l)swap(r,l);
            res=__gcd(res,tree.query(l,r));
        });
        return res;
    }
};

int main(){
    FAST
    // FILE_READ_IN
    // FILE_READ_OUT
    pre();
    int n;
    cin >> n;
    const int N = 100010;
    HLD<N,false> hld;
    for(int i = 1; i < n; ++i){int a,b;cin >> a >> b;hld.addEdge(a,b);}
    hld.init(N);
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        hld.modifyNode(i,a);
    }
    int q;
    cin >> q;
    ll e,f;
    while(q--){
        cin >> e >> f;
        cout << Ans(hld.queryPath(e,f)) << "\n";
    }
    return 0;
}
