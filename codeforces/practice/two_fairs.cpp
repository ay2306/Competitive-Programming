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
V<int> cnt;
int n,m,a,b;
int care;
void dfs(int s){
    vis[s] = true;
    cnt[s] = 1;
    for(auto i: adj[s]){
        if(!vis[i])dfs(i);
    }
}

void solve(){
    cin >> n >> m >> a >> b;
    a--;
    b--;
    adj = V<V<int>> (n);
    while(m--){
        int e,f;
        cin >> e >> f;
        e--;
        f--;
        adj[e].pb(f);
        adj[f].pb(e);
    }
    vis = V<bool> (n,false);
    cnt = V<int> (n,0);
    V<int> cnta,cntb;
    vis[b]=true;
    dfs(a);
    cnta = cnt;
    vis = V<bool> (n,false);
    cnt = V<int> (n,0);
    vis[a]=true;
    dfs(b);
    cntb = cnt;
    // loop(i,0,n)printf("%d ",cnta[i]);
    // printf("\n");
    // loop(i,0,n)printf("%d ",cntb[i]);
    // printf("\n");
    loop(i,0,n){
        if(cnta[i] == cntb[i])cnta[i]=0,cntb[i]=0;
    }
    cnta[a] = 0;
    cntb[b] = 0;
    // loop(i,0,n)printf("%d ",cnta[i]);
    // printf("\n");
    // loop(i,0,n)printf("%d ",cntb[i]);
    // printf("\n");
    cout << accumulate(all(cnta),0LL)*accumulate(all(cntb),0LL) << "\n";
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--)solve();
   return 0;
}