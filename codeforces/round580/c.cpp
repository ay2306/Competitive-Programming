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

void check(V<int> &arr){
      int n = arr.size()/2;
      unordered_map<int,int> m;
      int sum = 0;
      for(int i = 0; i < 2*n; ++i){
         sum = 0;
         int k = 0;
         for(int j = i; k < n; ++j,++k){
            sum+=arr[j%(2*n)];
         }
         m[sum]++;
      }
      if(m.size() > 2){
         cout << "NO\n";
         return;
      }
      V<ll> a;
      for(auto &i: m)a.pb(i.first);
      if(abs(a[0]-a[1]) > 1){
         cout << "NO\n";
         return;
      }
      cout << "YES\n";
}

int main(){
   // FILE_READ_OUT
   int n;
   cin >> n;
   if(n%2 == 0){
      cout << "NO\n";
      return 0;
   }
   if(n == 1){
      cout << "YES\n1 2";
      return 0;
   }
   V<int> sign(n,0);
   for(int i = 0; i < n; ++i){
      if(i%2 == 0)sign[i] = 1;
      else sign[i] = -1;
   }
   V<int> arr(2*n);
   arr[0] = 1;
   for(int i = 1; i < n; ++i){
      if(sign[i] == 1)arr[i] = arr[i-1]+1;
      else arr[i] = arr[i-1] + 3;
   }
   loop(i,n,2*n){
      arr[i] = arr[i-n]+sign[i-n];
   }
   cout << "YES\n";
   for(int i = 0; i < 2*n; ++i){
      cout << arr[i] << " ";
   }
   cout << endl;
   return 0;
}