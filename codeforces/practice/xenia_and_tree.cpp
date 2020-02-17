#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
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
// For ordered_set
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
const int ln = 20;
vector<set<int>> g;
int anc[ln][N];
int lev[N];
int ans[N];
// * LCA PROCESS
void dfs(int s = 0, int p = -1){
    anc[0][s] = p;
    if(p == -1)lev[s]=0;
    else lev[s] = lev[p]+1;
    for(auto &u: g[s]){
        if(u != p)dfs(u,s);
    }
}

void pre(){
    for(int i = 1; i < ln; ++i){
        for(int j = 0; j < g.size(); ++j){
            if(anc[i-1][j] != -1)anc[i][j] = anc[i-1][anc[i-1][j]];
        }
    }
}

int lca(int a, int b){
    if(lev[a] > lev[b])swap(a,b);
    int diff = lev[b]-lev[a];
    for(int i = ln-1; i >= 0; i--)if((diff>>i)&1)b=anc[i][b];
    if(a == b)return a;
    for(int i = ln-1; i >= 0; i--){
        if(anc[i][b] != anc[i][a]){
            a = anc[i][a];
            b = anc[i][b];
        }
    }
    return anc[0][a];
}

int dist(int a, int b){
    return lev[a]+lev[b]-2*lev[lca(a,b)];
}

// * LCA PROCESS
struct CentroidDecomposition{
    vector<set<int>> tree;
    vector<int> dad;
    vector<int> sub;
    CentroidDecomposition(vector<set<int>> &tree): tree(tree){
        int n = tree.size();
        dad.resize(n);
        sub.resize(n);
        build(0,-1);
    }
    void build(int u, int p){
        int n = dfs(u,p);
        int centroid = dfs(u,p,n);
        if(p == -1)p=centroid;
        dad[centroid]=p;
        vector<int> del;
        for(auto v: tree[centroid]){
            del.emplace_back(v);
            tree[v].erase(centroid);
            build(v,centroid);
        }
        for(auto &i: del)tree[centroid].erase(i);
    }
    int dfs(int u, int p){
        sub[u] = 1;
        for(auto v: tree[u]){
            if(v != p)sub[u]+=dfs(v,u);
        }
        return sub[u];
    }
    int dfs(int u, int p, int n){
        for(auto v: tree[u]){
            if(v != p && sub[v] > n/2)return dfs(v,u,n);
        }
        return u;
    }
    int operator[](int i){
        return dad[i];
    }
    void update(int u){
        int x = u;
        while(1){
            ans[x] = min(ans[x],dist(u,x));
            if(x == dad[x])break;
            x = dad[x];
        }
    }
    int query(int u){
        int x = u;
        int ret = inf;
        while(1){
            ret = min(ret,dist(u,x)+ans[x]);
            if(x == dad[x])break;
            x = dad[x];
        }
        return ret;
    }
};

int main(){
    FAST
    int n,m;
    cin >> n >> m;
    g = vector<set<int>> (n);
    for(int i = 1; i < n; ++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    dfs();
    pre();
    CentroidDecomposition obj(g);
    for(int i = 0; i < n; ++i)ans[i]=inf;
    obj.update(0);
    while(m--){
        int t,v;
        cin >> t >> v;
        if(t == 1)obj.update(v-1);
        else cout << obj.query(v-1) << "\n";
    }
   return 0;
}