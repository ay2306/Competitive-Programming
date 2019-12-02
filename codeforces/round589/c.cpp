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
V<ll> primes;

ll power(ll a, ll n){
   if(n == 0)return 1;
   if(n == 1)return a%MOD;
   ll p = power(a,n/2);
   p*=p;
   p%=MOD;
   if(n%2 == 1){p*=a; p %= MOD;}
   return p;
}

int main(){
   ll a[maxn] = {};
   for(int i = 2; i < maxn; ++i){
      if(a[i] == 0){
         for(int j = 2; i*j < maxn; ++j)a[i*j]++;
      }
   }
   loop(i,2,maxn){
      if(a[i] == 0)primes.pb(i);
   }
   ll x,n;
   cin >> x >> n;
   set<ll> factors;
   loop(i,2,maxn){
      if(a[i] == 0){
         if(x%i == 0){
            while(x%i == 0 && x > 1){
               x/=i;
            }
            factors.insert(i);
         }
      }
   }
   if(x > 1){
      factors.insert(x);
   }
   // for(ll i: factors){
   //    cout << i << "\n";
   // }
   ll ans = 1;
   for(ll i: factors){
      ll pw = 0;
      ll tn = n/i;
      while(tn > 0){
         pw+=tn;
         pw%=(MOD-1);
         tn/=i;
      }
      pw%=(MOD-1);
      ans*=power(i,pw);
      ans%=MOD;
   }
   cout << ans;
   return 0;
}