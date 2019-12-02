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
V<V<int>> scc;
V<V<int>> adj;
V<int> visited;
V<int> dfs_low;
V<int> dfs_num;
stack<int> s;
int n,m;
int iter = 0;
void dfs(int u){
    dfs_low[u] = dfs_num[u] = iter++;
    visited[u] = true;
    s.push(u);
    for(auto &i: adj[u]){
        if(!visited[u])dfs(i);
        dfs_low[u] = min(dfs_low[u],dfs_low[i]);
    }
    if(dfs_low[u] == dfs_num[u]){
        V<int> sc;
        while(1){
            sc.push_back(s.top());
            s.pop();
            if(sc.back() == u)break;
        }
        scc.push_back(sc);
    }
}

int main(){
    cin >> n >> m;
    adj = V<V<int>>(n);
    visited = V<int> (n,0);
    dfs_num = V<int> (n,0);
    dfs_low = V<int> (n,0);
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i])dfs(i);
    }
    int even = 0;
    int odd = 0;
    for(auto &i: scc){
        if(i.size()%2 == 0)even++;
        else odd++;
    }
    cout << odd << " " << even;
   return 0;
}