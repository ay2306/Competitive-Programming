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
#define time adsasda
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
V<int> g[N];
stack<int> s;
bool in[N];
ll cst[N];
ll ans;
int n,m;
ll ways = 1;
int dis[N], low[N], time;
void pop_stack(int start){
    ll mn = LLONG_MAX;
    unordered_map<ll,ll> op;
    // cout << "\nSCC = ";
    while(1){
        int node = s.top();
        s.pop();
        // cout << node  << " " ;
        in[node] = false;
        op[cst[node]]++;
        mn = min(mn,cst[node]);
        if(start == node)break;
    }
    ans+=mn;
    ways*=op[mn];
    ways%=MOD;
    // cout << endl;
    return;

}

void dfs(int u){
    dis[u] = low[u] = ++time;
    s.push(u);
    in[u] = true;
    for(auto v: g[u]){
        if(in[v])
            low[u]=min(low[u],low[v]);
        else if(dis[v]==0){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    }
    // printf("for node = %d, low = %d\n",u,low[u]);
    if(dis[u] == low[u])pop_stack(u);
}

int main(){
    int a,b;
    cin >> n;
    loop(i,1,n+1){
        cin >> cst[i];
    }
    cin >> m;
    while(m--){
        cin >> a >> b;
        g[a].pb(b);
    }
    loop(i,1,n+1){
        if(dis[i] == 0)dfs(i);
    }
    cout << ans << " " << ways;
   return 0;
}