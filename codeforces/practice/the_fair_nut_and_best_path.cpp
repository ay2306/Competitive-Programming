/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
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
using namespace std;

const ll maxn = 1e5;

class node{
public:
    ll dp;
    ll val;
    ll parent;
    node(){}
    node(ll a):dp(a),val(a){}
};


V<V<PLL> > adj;
V<bool> visited;
V<node> arr;
int n;
ll ans = 0;


ll solve(ll s = 0, ll parent = -1){
    if(visited[s])return arr[s].dp;
    for(auto i: adj[s]){
        if(i.F == parent)continue;
        solve(i.F,s);
        ans = max(ans,arr[i.F].dp + arr[s].dp - i.S);
        arr[s].dp = max(arr[i.F].dp + arr[s].val -i.S, arr[s].dp);
    }
    ans = max(arr[s].dp,ans);
}


int main(){
    cin >> n;
    adj = V<V<PLL> > (n,V<PLL>());
    visited = V<bool> (n,false);
    arr = V<node>(n);
    loop(i,0,n){
        ll a;
        cin >> a;
        arr[i] = node(a);
    }
    loop(i,1,n){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
    solve(0);
    cout << ans;
    return 0;
}