#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+110;
template<int N>
struct SegmentTree{
    int tree[(N+1)<<2];
    SegmentTree(){
        memset(tree,0,sizeof(tree));
    }
    void update(int id, int val, int node = 1, int start = 0, int end = N){
        if(start == end){
            tree[node] += val;
            return;
        }
        int mid = start + end >> 1;
        if(id <= mid)update(id,val,node<<1,start,mid);
        else update(id,val,node<<1|1,mid+1,end);
        tree[node] = max(tree[node<<1] , tree[node<<1|1]);
    }
    int query(int l, int r, int node = 1, int start = 0, int end = N){
        if(l > end || r < start)return INT_MIN;
        if(l <= start && end <= r)return tree[node];
        int mid = start + end >> 1;
        return max(query(l,r,node<<1,start,mid),query(l,r,node<<1|1,mid+1,end));
    }
};
template<int N>
struct HLD{
    int pos[N],par[N],root[N];
    int sz[N],lev[N];
    vector<int> g[N];
    void addEdge(int a, int b){
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int dfs_subsize(int s){
        if(par[s])g[s].erase(find(g[s].begin(),g[s].end(),par[s]));
        sz[s] = 1;
        for(int &u: g[s]){
            par[u] = s;
            lev[u] = lev[s] + 1;
            sz[s] += dfs_subsize(u);
            if(sz[u] > sz[g[s][0]])swap(u,g[s][0]);
        }
        return sz[s];
    }
    void decompose(int s){
        static int timer = 0;
        pos[s] = timer++; 
        
        for(int u: g[s]){
            root[u] = (u==g[s][0])?root[s]:u;
            decompose(u);
        }
    }
    void init(){
        root[1] = 1;
        lev[1] = 1;
        par[1] = 0;
        dfs_subsize(1);
        decompose(1);
    }
    SegmentTree<(N+100)> tree;
    template<class BinaryOp>
    void processPath(int u, int v, BinaryOp op){
        for(;root[v] != root[u]; v = par[root[v]]){
            if(lev[root[v]] < lev[root[u]])swap(u,v);
            op(pos[root[v]],pos[v]);
        }
        if(lev[u] > lev[v])swap(u,v);
        op(pos[u],pos[v]);
    }
    void updateNode(int u, int val){
        processPath(u,u,[&](int l, int r)->void{
            if(l > r)swap(l,r);
            tree.update(l,val);
        });
    }
    int queryPath(int u, int v){
        int res = INT_MIN;
        processPath(u,v,[&](int l, int r)->void{
            if(l > r)swap(l,r);
            res = max(tree.query(l,r),res);
        });
        return res;
    }
};
int32_t main(){
    int n,q;
    cin >> n >> q;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; ++i)cin >> arr[i];
    HLD<N> left,right;
    stack<int> s;
    for(int i = 1; i <= n; ++i){
        while(s.size() && arr[s.top()] > arr[i]){
            right.addEdge(s.top(),i);
            s.pop();
        }
        s.emplace(i);
    }
    while(s.size())s.pop();
    for(int i = n; i > 0; --i){
        while(s.size() && arr[s.top()] > arr[i]){
            left.addEdge(s.top(),i);
            s.pop();
        }
        s.emplace(i);
    }
    left.init();
    right.init();
    while(s.size())s.pop();
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        left.updateNode(i,a);
        right.updateNode(i,a);
    }
    while(q--){
        int s,e,type;
        cin >> type >> s >> e;
        if(type == 1){
            left.updateNode(s,e);
            right.updateNode(s,e);
        }else{
            if(s >= e){
                cout << right.queryPath(s,e) << "\n";
            }else{
                cout << left.queryPath(s,e) << "\n";
            }
        }
    }
    return 0;
}