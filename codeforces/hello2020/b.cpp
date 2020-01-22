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

void solve(){
   int n;
   ord_set<PLL> m;
   ord_set<PLL> m1;
   ll a;
   int g=0;
   cin >> n;
   V<PLL> arr;
   V<ll> mnr;
   V<int> good(n,0);
   ll ans = 0;
   int c = 0;
   loop(i,0,n){
      int k;
      cin >> k;
      if(k == 0)continue;
      ll mn = LLONG_MAX;
      ll mx = LLONG_MIN;
      while(k--){
         cin >> a;
         mn = min (a,mn);
         mx = max (a,mx);
         if(a > mn){
            good[i] = 1;
         }

      }
      if(good[i])ans+=(n+n-1-2*g),g++;
      else{
         arr.pb({mn,mx}),mnr.pb(mn);
      }
   }
   n = arr.size();
   // int o = 1;
   // for(auto it = arr.begin(); it != arr.end() ; ++it){
   //    auto i = *it;
   //    ll mn = i.F;
   //    ll mx = i.S;
   //    m.insert({mx,-1});
   //    ans += m.order_of_key({mx,-1});
   //    // printf("index = %d,   t = %d, ans = %lld\n",int(it-arr.begin()),t,ans);
   //    m.erase({mx,-1});
   //    m.insert({mn,o++});
   // }
   // reverse(all(arr));
   // for(auto it = arr.begin(); it != arr.end() ; ++it){
   //    auto i = *it;
   //    ll mn = i.F;
   //    ll mx = i.S;
   //    m1.insert({mx,-1});
   //    ans += m1.order_of_key({mx,-1});
   //    // printf("index = %d, t = %d, ans = %lld\n",int(it-arr.begin()),t,ans);
   //    m1.erase({mx,-1});
   //    m1.insert({mn,o++});
   // }
   sort(all(mnr));
   sort(all(arr));
   // loop(i,0,n){
   //    cout << mnr[i] << " ";
   // }
   // cout << endl;
   loop(i,0,n){
      int ind=(lower_bound(all(mnr),arr[i].S)-mnr.begin());
      if(ind > i && arr[i].F == arr[i].S)ind--;
      ans+=ind;
      // cout << arr[i].S << " " << ans << "\n";
   }
   std::cout << ans << "\n";
}

int main(){
   int t = 1;
//    cin >> t;
   while(t--){
       solve();
   }
   return 0;
}