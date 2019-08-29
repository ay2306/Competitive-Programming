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

V<V<int>> adj;
V<bool> vis;
V<int> dfs_num;
V<int> dfs_low;
int iter = 0;
int n,m;
set<pair<int,int>> bridge;
void dfs(int s, int p = -1){
    dfs_num[s] = dfs_low[s] = iter++;
    vis[s] = true;
    for(auto &i: adj[s]){
        if(i == p)continue;
        if(!vis[i]){
            dfs(i,s);
            if(dfs_low[i] > dfs_num[s])bridge.insert(mp(min(i,s),max(i,s)));
            dfs_low[s] = min(dfs_low[i],dfs_low[s]);
        }else{
            dfs_low[s] = min(dfs_low[i],dfs_low[s]);
        }
    }
}

int main(){
    cin >> n >> m;
    int q;
    cin >> q;
    adj = V<V<int>> (n);
    dfs_low = V<int> (n,0);
    dfs_num = V<int> (n,0);
    vis = V<bool> (n,false);
    map<int,PII> edge;
    while(m--){
        int a,b;
        int id;
        cin >> a >> b >> id;
        a--;
        b--;
        edge[id] = (mp(min(a,b),max(a,b)));
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs(i);
        }
    }
    while(q--){
        int a;
        cin >> a;
        if(bridge.find(edge[a]) != bridge.end()){
            cout << "YES\n";
        }else{
            cout << "no\n";
        }
    }
   return 0;
}