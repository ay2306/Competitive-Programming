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
V<int> col;
V<bool> vis;
int main(){
    FAST
    int n,m;
    cin >> n >> m;
    vis = V<bool> (n,false);
    adj = V<V<int>> (n);
    col = V<int> (n);
    int ans = 0;
    unordered_map<int,V<int>> op;
    int c = inf;
    loop(i,0,n){cin >> col[i];op[col[i]].pb(i);c=min(c,col[i]);}
    int a,b;
    while(m--){
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(auto i: op){
        int ct = 0;
        unordered_map<int,int> cop;
        for(auto s: i.S){
            for(auto v: adj[s]){
                if(col[v] != i.F && cop.find(col[v]) == cop.end())ct++,cop[col[v]]++;
            }
        }
        // cout << "--  " <<  i.F << " " << ct << "\n";
        if(ct > ans){
            ans = ct;
            c = i.F;
        }else if(ct == ans){
            c = min(c,i.F);
        }
    }
    cout << c;
   return 0;
}