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
int n,m;
V<V<int>> adj;
V<int> num_low;
V<int> parent;
V<int> num_first;
V<int> visited;
V<int> art;
int iter = 0;
int root = 0;
int root_children = 0;
void dfs(int s = 0, int p = -1){
    num_low[s] = num_first[s] = iter++;
    visited[s] = 1;
    for(auto &v: adj[s]){
        if(v == p)continue;
        if(visited[v] == 0){
            if(s == 0){
                root_children++;
            }
            dfs(v,s);
            if(num_low[v] >= num_first[s])art[s] = 1;
            num_low[s] = min(num_low[s],num_low[v]);
        }else{
            num_low[s] = min(num_low[s],num_low[v]);
        }
    }
}
int main(){
    cin >> n >> m;
    adj = V<V<int>> (n);
    num_low = V<int> (n,0);
    art = V<int> (n,0);
    num_first = V<int> (n,0);
    visited = V<int> (n,0);
    parent = V<int> (n,-1);
    for(int i = 0 ; i < m; ++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            root_children = 0;
            root = i;
            dfs(i);
            art[root] = (root_children > 1);
        }
    }
    // for(int i: art)cout << i << " ";
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        a--;
        if(art[a])cout << "Satisfied " << adj[a].size() << "\n";
        else cout << "Not Satisfied\n";
    }
   return 0;
}