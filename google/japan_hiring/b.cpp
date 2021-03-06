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
V<V<int>> adj;
V<int> level;
int n;
void bfs(int s){
    queue<int> q;
    V<bool> vis (n,false);
    vis[s] = true;
    level[s] = 0;
    q.push(s);
    while(q.size()){
        s = q.front();
        q.pop();
        for(auto &i: adj[s]){
            if(!vis[i]){
                level[i] = level[s]+1;
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

void solve(){
    cin >> n;
    adj = V<V<int>> (n,V<int>());
    level = V<int> (n);
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = n+1;
    loop(i,0,n){
        bfs(i);
        ans = min(ans,*max_element(all(level)));
    }
    printf("%d\n",ans);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    loop(i,1,t+1){
        printf("Case #%d: ",i);
        solve();
    }
}