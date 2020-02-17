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
const ll maxn = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);

set<int> s;
set<int> g[maxn];
int sz = 0;

void dfs(int u){
    V<int> next;sz++;
    s.erase(u);
    for(auto i: s)if(g[u].find(i) == g[u].end())next.pb(i);
    for(auto i: next)s.erase(i);
    for(auto i: next)dfs(i);
}
int main(){
    FAST
    int n,m,a,b;
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    loop(i,1,n+1)s.insert(i);
    int ans = 0;
    loop(i,1,n+1){
        if(s.find(i) != s.end())dfs(i),ans++;
    }
    cout << ans-1 << "\n";
   return 0;
}