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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N = 10100;
const int LN = 14;
const ll inf = 1e9;
const double pi = acos(-1);
V<int> adj[N],costs[N],indexx[N];
int arr[N],ptr;
int chainNo,chainInd[N],chainHead[N],posInArr[N];
int depth[N],pa[LN][N],otherEnd[N],subsize[N];
int st[N*6],qt[N*6];

void dfs(int cur, int prev, int _depth = 0){
    pa[0][cur] = prev;
    depth[cur] = _depth;
    subsize[cur] = 1;
    for(int i = 0; i < (int)adj[cur].size(); ++i){
        if(adj[cur][i] == prev)continue;
        otherEnd[indexx[cur][i]] = adj[cur][i];
        dfs(adj[cur][i],cur,_depth+1);
        subsize[cur]+=subsize[adj[cur][i]];
    }
}

void solve(){
    ptr = 0;
    int n;
    scanf("%d",&n);
    loop(i,0,n){
        adj[i].clear();
        costs[i].clear();
        indexx[i].clear();
        chainHead[i] = -1;
        for(int i = 0; i < LN; ++i)pa[j][i] = -1;
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
}

int main(){
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}