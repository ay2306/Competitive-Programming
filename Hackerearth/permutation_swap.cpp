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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

vector<int> parent;
vector<vector<int>> adj;
int n,k;
vector<bool> vis;
void bfs(int s){
    queue<int> q;
    q.push(s);
    parent[s] = s;
    vis[s] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto &i: adj[u]){
            if(vis[i])continue;
            parent[i] = s;
            vis[i] =  true;
            q.push(i);
        }
    }
}

void solve(){
    cin >> n >> k;
    parent = V<int> (n);
    vis = V<bool> (n,false);
    adj = V<V<int>> (n);
    unordered_map<int,int> m;
    loop(i,0,n){
        int a;
        cin >> a;
        m[a]=i;
    }
    V<int> arr(n);
    loop(i,0,n){
        cin >> arr[i];
    }
    loop(i,0,k){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    loop(i,0,n){
        if(!vis[i]){
            bfs(i);
        }
    }
    bool p = true;
    loop(i,0,n){
        // printf("parent(i = %d) = %d, parent(m[arr[i]] = %d) = %d\n",i,parent[i],m[arr[i]],parent[m[arr[i]]]);
        if(parent[i] != parent[m[arr[i]]]){
            p = false;
            break;
        }
    }
    if(p)cout << "YES\n";
    if(!p)cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}