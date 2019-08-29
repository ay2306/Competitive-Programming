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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
V<V<int>> adj;
V<int> level;
V<bool> vis;
int ans;

void bfs(int s){
    level[s] = 1;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto &v: adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
                level[v] = level[u]+1;
                ans = max(ans,level[v]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    adj = V<V<int>> (n);
    level = V<int> (n,0);
    V<int> root;
    ans = 1;
    loop(i,0,n){
        int a;
        cin >> a;
        if(a == -1){
            root.pb(i);
        }else{
            adj[a-1].pb(i);
        }
    }
    vis = V<bool> (n,false);
    for(auto &i: root){
        if(!vis[i])bfs(i);
    }
    cout << ans << "\n";
    return 0;
}