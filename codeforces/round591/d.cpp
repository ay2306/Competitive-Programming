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
const ll N = 3e5+10;
const ll inf = 1e9;
const double pi = acos(-1);

int arr[N];
int n;

void solve(){
   int n;
   cin >> n;
   loop(i,0,n)cin >> arr[i];
   set<int> s;
   loop(i,0,n)s.insert(arr[i]);
   V<int> a;
   for(auto i: s)a.pb(i);
   int left = 0;
   int right = 0;
   loop(i,1,n){
      if(arr[i-1] > arr[i]){
         if(left == 0)left = arr[i];
         else left = max(left,arr[i]);
      }
   }
   loopr(i,n-2,0){
      if(arr[i] > arr[i+1]){
         if(right == 0)right = arr[i];
         else right = min(right,arr[i]);
      }
   }
   cout << left << " " << right << "\n";
   if(right == 0 || left == 0){
      cout << 0 << "\n";
      return ;
   }
   left = upper_bound(all(a),left) - a.begin();
   right = upper_bound(all(a),right) - a.begin();
   left++;
   right = a.size()-right;
   cout << min(left,right) << "\n";
}

int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
   return 0;
}