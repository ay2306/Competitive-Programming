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

struct prob{
   ll m;
   ll pref;
   ll ti;
   prob(ll a, ll b, ll c):m(a),pref(b),ti(c){}
};

void solve(){
   ll n,ti,a,b;
   cin >> n >> ti >> a >> b;
   unordered_map<int,bool> m;
   V<prob> arr;
   ll ans = 0, easy = 0, hard = 0, mand_easy = 0, mand_hard = 0;
   loop(i,0,n){
      int k;
      cin >> k;
      if(k == 0){
         arr.pb(prob(a,a,a));
         easy++;
      }else{
         hard++;
         arr.pb(prob(b,b,b));
      }
   }
   loop(i,0,n){
      cin >> arr[i].ti;
   }
   sort(all(arr),[](prob &a,prob &b)->bool{
      return a.ti < b.ti;
   });
   if(easy * a + hard*b <= ti){
      cout << easy+hard << "\n";
      return;
   }
   loop(i,0,n){
      ll pos = 0;
      ll t = arr[i].ti-1;
      if(mand_hard * b + mand_easy*a <= t){
         pos = mand_easy + mand_hard;
         t-=(a*mand_easy);
         t-=(b*mand_hard);
         ll e = min(t/a,easy-mand_easy);
         t-=(a*e);
         ll h = min(t/b,hard-mand_hard);
         ans = max(ans,pos+e+h);
         // printf("t = %lld, mhard = %lld, measy = %lld, e = %lld, h = %lld, ans = %lld\n",arr[i].ti-1,mand_hard,mand_easy,e,h,ans);
      }
      if(arr[i].m == a)mand_easy++;
      else mand_hard++;
   }
   cout << ans << "\n";
}

int main(){
   FAST
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}