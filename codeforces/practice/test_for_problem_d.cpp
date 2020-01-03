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
const ll N = 5e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int n;
PII ans[N];
int cur = 1;
V<int> adj[N];

void dfs(int s = 0, int p = -1){
    for(auto v: adj[s]){
        if(v == p)continue;
        dfs(v,s);
    }
    ans[s].F = cur++;
    for(auto it = adj[s].rbegin(); it != adj[s].rend(); ++it){
        if(*it  == p)continue;
        ans[*it].S = cur++;
    }
}


int main(){
    FAST
    cin >> n;
    int a,b;
    loop(i,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    ans[0].S = 2*n;
    loop(i,0,n)cout << ans[i].F << " " << ans[i].S << "\n";
   return 0;
}