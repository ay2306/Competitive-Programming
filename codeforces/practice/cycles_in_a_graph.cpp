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
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m,k;
PII vis[N];
V<int> adj[N];
int parent[N];
bool cf = false;
int cn;
int fn;
void dfs(int s = 1,int l = 0){
    // cout << s << " " << l << "\n";
    vis[s] = {1,l};
    for(auto i: adj[s]){
        if(cf)return;
        if(i == parent[s])continue;
        if(vis[i].F == 1 && l-vis[i].S+1 > k){
            cn=s;
            cf=true;
            fn=i;
            return;
        }
        if(vis[i].F == 0)parent[i]=s,dfs(i,l+1);
    }
    vis[s] = {1,l};
}
int main(){
    cin >> n >> m >> k;
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    if(cf){
        stack<int> ans;
        int p = cn;
        while(p != 0){
            ans.push(p);
            if(p == fn)break;
            p=parent[p];
        }
        cout << ans.size() << "\n";
        while(ans.size()){
            cout << ans.top() << " ";
            ans.pop();
        }
    }
   return 0;
}