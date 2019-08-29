/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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
#define ord_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
const ll maxn = 1e5;
V<V<PLL>> adj;
V<int> color;
V<bool> vis;

void dfs(int s = 0, int p = -1){
    vis[s] = true;
    for(auto &i: adj[s]){
        if(i.F == p)continue;
        if(i.S % 2 == 0)color[i.F] = color[s];
        else color[i.F] = 1-color[s];
        dfs(i.F,s);
    }
}

int main(){
    int n;
    cin >> n;
    adj = V<V<PLL>>(n,V<PLL>());
    color = V<int> (n,0);
    vis = V<bool> (n,false);
    loop(i,1,n){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a-1].pb(mp(b-1,c));
        adj[b-1].pb(mp(a-1,c));
    }
    dfs();
    loop(i,0,n){
        cout << color[i] << "\n";
    }
    return 0;
}