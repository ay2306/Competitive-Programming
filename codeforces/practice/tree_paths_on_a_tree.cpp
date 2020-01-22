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
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
V<V<int>> adj;
V<int> level;
V<int> parent;
V<int> vis;
int dfs(int s, int p = -1){
    int mx = s;
    parent[s]=p;
    if(p == -1)level[s] = 0;
    else level[s]=level[p]+1;
    for(auto i: adj[s]){
        if(i == p)continue;
        if(vis[i])continue;
        int h = dfs(i,s);
        if(level[h] > level[mx])mx=h;
    }
    return mx;
}
void solve(){
    int n,m;
    cin >> n;
    m = n-1;
    adj = V<V<int>> (n);
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    level=V<int>(n,-1);
    parent=V<int>(n,-1);
    vis=V<int>(n,0);
    int ans[3];
    ans[0] = dfs(0);
    level=V<int>(n,-1);
    parent=V<int>(n,-1);
    ans[1] = dfs(ans[0]);
    int p = ans[1];
    int k = level[p];
    while(p != -1){
        vis[p] = 1;
        p = parent[p];
    }
    int mx = -1;
    loop(i,0,n){
        if(vis[i] && i != ans[0] && i != ans[1]){
            int a = dfs(i);
            if(mx < level[a]){
                ans[2]=a;
                mx=level[a];
            }
        }
    }
    cout << k + mx << "\n";
    loop(i,0,3)cout << ans[i]+1 << " ";
}

int main(){
    FAST
   int t = 1;
//    cin >> t;
   while(t--){
       solve();
   }
   return 0;
}