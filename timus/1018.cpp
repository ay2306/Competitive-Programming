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
V<int> parent;
V<int> leaf;
V<int> subTreeSum;
V<int> subTreeEdges;
long long int ans = LLONG_MAX;
void dfs(int s = 0, int p = -1){
    parent[s] = p;
    int cnt = 0;
    for(auto i: adj[s]){
        if(i == p)continue;
        dfs(i,s);
        subTreeSum[s]+=subTreeSum[i];
        subTreeEdges[s]+=(subTreeEdges[i]+1);
    }
}
int main(){
    FAST
    map<PII,int> ed;
    int n,m;
    cin >> n >> m;
    int to_del = n-1-m;
    adj = V<V<int>> (n);
    parent = V<int> (n,0);
    leaf = V<int> (n,0);
    subTreeSum = V<int> (n,0);
    subTreeEdges = V<int> (n,0);
    int ans =0 ;
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        int c;
        cin >> c;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        ed[{a,b}] = c;
        ed[{b,a}] = c;
        ans+=c;
    }
    cout << ans;
   return 0;
}