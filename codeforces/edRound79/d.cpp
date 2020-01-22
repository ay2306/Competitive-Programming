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
const ll mod = 998244353;
const ll inf = 1e9;
const double pi = acos(-1);

ll power(ll a, ll n){
   if(n == 0)return 1LL;
   if(n == 1)return a%mod;
   ll p = power(a,n/2);
   p*=p;
   p%=mod;
   if(n&1){p*=a;p%=mod;}
   return p;
}

void solve(){
   ll n;
   cin >> n;
   unordered_map<int,ll> want;
   V<V<int>> arr(n);
   int k;
   int a;
   loop(i,0,n){
      cin >> k;
      while(k--){
         cin >> a;
         arr[i].pb(a);
         want[a]++;
      }
   }
   ll ans = 0;
   ll denom = power(n,mod-2);
   loop(i,0,n){
      // * this is choosen
      ll num =power(arr[i].size(),mod-2);
      for(auto j: arr[i]){
         ll prob = 1;
         prob*=denom;
         prob*=num;
         prob%=mod;
         // * approp child is choosen
         ll ap_child = want[j];
         ap_child*=denom;
         ap_child%=mod;
         prob*=ap_child;
         prob%=mod;
         ans+=prob;
         ans%=mod;
      }
   }
   cout << ans << "\n";
}

int main(){
   FAST
   ll t = 1;
   while(t--)solve();
   return 0;
}