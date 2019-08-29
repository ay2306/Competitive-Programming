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
V<bool> visited;
V<int> color;
bool dfs(int s, int col = 0){
    visited[s] = true;
    color[s] = col;
    bool pos = true;
    for(int &i: adj[s]){
        if(!visited[i])pos&=dfs(i,1-col);
        else if(color[i] == col)pos=false;
    }
    return pos;
}

void solve(int scenario){
    int n,m;
    cin >> n >> m;
    adj = V<V<int>> (n);
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool result = true;
    visited = V<bool> (n,false);
    color = V<int> (n,-1);
    loop(i,0,n){
        if(!visited[i]){
            cout << i << "\n";
            result &= dfs(i);
        }
        if(!result)break;
    }
    if(result){
        printf("Scenario #%d:\nNo suspicious bugs found!\n",scenario);
    }else{
        printf("Scenario #%d:\nSuspicious bugs found!\n",scenario);
    }
}
int main(){
    int t;
    cin >> t;
    loop(i,1,t+1){
        solve(i);
    }
   return 0;
}