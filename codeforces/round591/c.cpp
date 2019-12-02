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
V<ll> arr;
V<ll> dis;

ll check(ll n){
   // printf("n = %lld\n",n);
   priority_queue<ll> p;
   loop(i,0,n)p.push(dis[i]);
   ll ans = 0;
   loop(i,0,n){
      ll val = arr[arr.size()-1-i];
      ll disc = p.top();
      p.pop();
      val/=100;
      ans+=(val*disc);
      // printf("val = %lld , disc = %lld, total = %lld, ans = %lld\n",val,disc,val*disc,ans);
   }
   return ans;
}

void solve(){
   int n;
   cin >> n;
   arr = V<ll> (n);
   loop(i,0,n)cin >> arr[i];
   int x,a;
   int y,b;
   dis = V<ll> (n,0);
   cin >> x >> a;
   cin >> y >> b;
   sort(all(arr));
   loop(i,1,n+1){
      if(i % a == 0){
         dis[i-1]+=x;
      }
      if(i % b == 0){
         dis[i-1]+=y;
      }
   }
   ll k = 0;
   cin >> k;
   ll ans = -1;
   ll low = 1;
   ll high = n;
   while(low <= high){
      ll mid = ((low+high)>>1);
      ll val = check(mid);
      // cout <<val << "\n";
      if(val >= k){
         high = mid-1;
         ans = mid;
      }else{
         low = mid+1;
      }
   }
   cout << ans << "\n";
}

int main(){
  FILE_READ_IN
    FILE_READ_OUT
   FAST
   int t;cin >> t;
   while(t--)solve();
   return 0;
}
