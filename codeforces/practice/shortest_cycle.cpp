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
#define all(a) a.begin(),a.end()
#define FILE_READ_IN freopen("input.txt","r",st
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
V<int> level;
V<int> parent;

int main(){
    int n;
    cin >> n;
    V<ll> arr;
    ll a;
    loop(i,0,n){
        cin >> a;
        if(a)arr.pb(a);
    }
    n = arr.size();
    adj = V<V<int>> (n);
    ll mx = *max_element(all(arr));
    int b = 0;
    while((mx >> b) > 0){
        int cnt = 0;
        for(auto i: arr)cnt+=((i>>b)&1);
        if(cnt >= 3){
            cout << 3;
            return 0;
        }
        b++;
    }
    loop(i,0,n){
        loop(j,i+1,n){
            if((arr[i]&arr[j])){
                adj[i].pb(j);
                adj[j].pb(i);
                // cout << i << " " << j << "\n";
            }
        }
    }
    int ans = inf;
    loop(v,0,n){
        queue<int> q;
        level = V<int> (n,inf);
        parent = V<int> (n,-1);
        level[v] = 0;
        q.push(v);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto i: adj[u]){
                if(i == parent[u])continue;
                if(level[i] == inf){
                    level[i] = level[u]+1;
                    parent[i] = u;
                    q.push(i);
                }else{
                    ans=min(ans,level[u]+level[i]+1);
                    // printf("u = %d, i = %d, level[%d] = %d, level[%d] = %d\n",u,i,u,level[u],i,level[i]);
                }
            }
        }
    }
    if(ans == inf)ans=-1;
    cout << ans;
   return 0;
}