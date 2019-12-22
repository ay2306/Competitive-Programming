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
ll n,k;
unordered_map<ll,ll> m;
ll g(ll t){
   if(t > n)return 0;
   if(m.find(t) != m.end())return m[t];
   if(t & 1LL){
      m[t] =  g(2*t)+1;
   }else{
      m[t] = g(2*t) + g(t+1) + 1;
   }
   return m[t];
}

int main(){
   // FILE_READ_OUT
   cin >> n >> k;
   ll low = 1;
   ll high = (n >> 1);
   ll ans = -1;
   // * Binary Search for even cases
   while(low <= high){
      m = unordered_map<ll,ll>();
      ll mid = ((low + high) >> 1);
      ll paths = g(2*mid);
      if(paths < k){
         high = mid-1;
      }else if(paths >= k){
         low = mid+1;
         ans = max(ans,2*mid);
      }
   }
   // * Binary Search for odd cases
   high=(n-1)/2;
   low = 0;
   while(low <= high){
      m = unordered_map<ll,ll>();
      ll mid = ((low + high) >> 1);
      ll paths = g(2*mid+1);
      if(paths < k){
         high = mid-1;
      }else if(paths >= k){
         low = mid+1;
         ans = max(ans,2*mid+1);
      }
   }
   cout << ans;
   return 0;
}