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
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
const int root = 0;
const int N = 10100;
const int LN = 14;
int n;
V<int> adj[N],costs[N],indexx[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];




void HLD(int curNode, int cost, int p){
    if(chainHead[chainNo] == -1){
        chainHead[chainNo] = curNode;
    }
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr;
    baseArray[ptr++] = cost;

    int sc = -1,ncost;
    for(int i = 0; i < adj[curNode].size(); ++i){
        if(adj[curNode][i] == p)continue;
        if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]){
            sc = subsize[adj[curNode][i]];
            ncost = costs[curNode][i];

        }
    }
    if(sc != -1){
        HLD(sc,ncost,curNode);
    }
    for(int i = 0; i < adj[curNode].size(); ++i){
        if(adj[curNode][i] == p)continue;
        if(adj[curNode][i] == sc)continue;
        chainNo++;
        HLD(adj[curNode][i],costs[curNode][i],curNode);
    }

}

void dfs(int cur, int p, int _depth = 0){
    pa[0][cur] = p;
    depth[cur] = _depth;
    subsize[cur] = 1;
    loop(i,0,adj[cur].size()){
        if(adj[cur][i] != p){
            otherEnd[indexx[cur][i]] = adj[cur][i];
            dfs(adj[cur][i],cur,_depth+1);
            subsize[cur]+=subsize[adj[cur][i]];
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ptr = 0;
        int n;
        scanf("%d",&n);
        loop(i,0,n){
            adj[i].clear();
            costs[i].clear();
            indexx[i].clear();
            chainHead[i] = -1;
            loop(j,0,LN)pa[j][i] = -1;
        }
        loop(i,1,n){
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
            costs[u].pb(c);
            costs[v].pb(c);
            indexx[u].pb(i-1);
            indexx[v].pb(i-1);
        }
        chainNo = 0;
        dfs(root,-1);
        HLD(root,-1,-1);
    }
   return 0;
}