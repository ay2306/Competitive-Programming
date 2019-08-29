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

ll val(ll K){
   return int(ceil(log2(K)));
}

int main(){
   ll n,I;
   cin >> n >> I;
   V<ll> arr(n);
   loop(i,0,n)cin >> arr[i];
   unordered_map<ll,ll> m;
   loop(i,0,n)m[arr[i]]++;
   V<PLL> p;
   for(auto &i: m){
      p.pb(mp(i.F,i.S));
   }
   sort(all(p));
   if(val(1LL*(p.size()))*n <= I*8){
      cout << 0;
      return 0;
   }
   ll ans = 0;
   int i = 0;
   int j = n-1;
   ll low = 1;
   ll high = 1000000;
   ll k = 0;
   while(low <= high){
      ll mid = ((low + high)/2);
      if(val(mid)*n > I*8){
         high = mid-1;
      }else{
         low = mid+1;
         k = max(ans,mid);
      }
   }
   // cout << k << "\n";
   V<ll> pref;
   pref.pb(p[0].second);
   loop(i,1,p.size()){
      pref.pb(pref.back()+p[i].second);
   }
   V<ll> suff(p.size(),p.back().second);
   for(int i = p.size()-2; i >= 0; --i){
      suff[i] = suff[i+1] + p[i].second;
   }
   i = 0;
   j = k-1;
   ans = LLONG_MAX;
   // for(auto i: suff){
   //    printf("%lld ",i);
   // }
   // printf("\n");
   // for(auto i: pref){
   //    printf("%lld ",i);
   // }
   // printf("\n");
   while(j < p.size()){
      // printf("i = %d j = %d",i,j);
      ll ps = 0;
      if(i-1 >=0)ps = pref[i-1];
      ll ss = 0;
      if(j+1 < p.size()){
         ss = suff[j+1];
      }
      // cout << ps << " " << ss << "\n";
      ans = min(ss+ps,ans);
      i++;
      j++;
   }
   cout << ans;
   return 0;
}