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
V<int> a,b,c;
set<int> considered;
V<V<int>> must;
V<int> expendibles;
V<int> sol_at_state;
V<int> a_min;
int main(){
   int n,m,k;
   cin >> n >> m >> k;
   adj = V<V<int>> (n+1);
   a = V<int> (n+1);
   b = V<int> (n+1);
   c = V<int> (n+1);
   expendibles = V<int> (n+1,0);
   sol_at_state = V<int> (n+1,0);
   a_min = V<int> (n+1);
   loop(i,1,n+1){
      cin >> a[i] >> b[i] >> c[i];
   }
   loop(i,0,m){
      int a,b;
      cin >> a >> b;
      if(a > b)swap(a,b);
      adj[a].pb(b);
   }
   loopr(i,n,1){
      if(considered.find(i) == considered.end()){
         must[i].pb(i);
         considered.insert(i);
      }
      for(int j: adj[i]){
         if(considered.find(j) == considered.end()){
            must[i].pb(j);
            considered.insert(j);
         }
      }
   }
   // * First we will check if it is even possible to capture all targets
   // * And Count Expendibles
   int current = k;
   loop(i,1,n+1){
      if(a[i] > current){
         cout << "-1";
         return 0;
      }
      current+=b[i];
      sol_at_state[i] = current;
   }
   int ans = 0;
   
   return 0;
}