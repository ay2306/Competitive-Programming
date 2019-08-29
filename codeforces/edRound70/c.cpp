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

void solve(){
   string a;
   cin >> a;
   ll x = 0;
   ll y = 0;
   ll minx = 0;
   ll miny = 0;
   ll maxx = 0;
   ll maxy = 0;
   unordered_map<ll,ll> m;
   unordered_map<ll,ll> lst_y;
   unordered_map<ll,ll> lst_x;
   unordered_map<ll,ll> first_y;
   unordered_map<ll,ll> first_x;
   lst_x[x] = 0;
   lst_y[y] = 0;
   for(int i = 0; i < a.size(); ++i){
      char k = a[i];
      if(k=='W'){ y++; m[y]++;lst_y[y] = i;}
      if(k=='S'){ y--; m[y]++;lst_y[y] = i;}
      if(k=='A'){ x--; m[x]++;lst_x[x] = i;}
      if(k=='D'){ x++; m[x]++;lst_x[x] = i;}
      if(first_x.find(x) == first_x.end())first_x[x]=i;
      if(first_y.find(y) == first_y.end())first_y[y]=i;
      maxx = max(x,maxx);
      maxy = max(y,maxy);
      minx = min(x,minx);
      miny = min(y,miny);
   }
   ll ans =(maxx-minx+1)*(maxy-miny+1);
   if((lst_x[maxx] > first_x[minx] || lst_x[minx] > first_x[maxx]) && maxx-miny >= 2){
      ans = min(ans,(maxx-1-minx+1)*(maxy-miny+1));
   }
   if((lst_y[maxy] > first_y[miny] || lst_y[miny] > first_y[maxy]) && maxy-miny >= 2){
      ans = min(ans,(maxx-minx+1)*(maxy-miny));
   }
   cout << ans << "\n";
}

int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
   return 0;
}