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
bool check(string &a){
   loop(i,1,a.size()){
      if(a[i] != a[i-1])return false;
   }
   return true;
}
char change(char a){
   if(a == 'W')return 'B';
   return 'W';
}
int main(){
   string a,orig;
   int n;
   cin >> n;
   cin >> a;
   orig = a;
   V<int> ans;
   // * Check 1
   loop(i,1,n-1){
      if(a[i] == a[0])continue;
      a[i] = change(a[i]);
      a[i+1] = change(a[i+1]);
      ans.pb(i+1);
   }
   if(check(a)){
      cout << ans.size() << "\n";
      for(int i : ans)cout << i << " ";
      return 0;
   }
   // cout << a << "\n";
   loop(i,0,n-2){
      if(a[i] == a[n-1])continue;
      a[i] = change(a[i]);
      a[i+1] = change(a[i+1]);
      ans.pb(i+1);
   }
   if(check(a)){
      cout << ans.size() << "\n";
      for(int i : ans)cout << i << " ";
      return 0;
   }
   loop(i,1,n-1){
      if(a[i] == a[0])continue;
      a[i] = change(a[i]);
      a[i+1] = change(a[i+1]);
      ans.pb(i+1);
   }
   if(check(a)){
      cout << ans.size() << "\n";
      for(int i : ans)cout << i << " ";
      return 0;
   }
   // cout << a << "\n";
   loop(i,0,n-2){
      if(a[i] == a[n-1])continue;
      a[i] = change(a[i]);
      a[i+1] = change(a[i+1]);
      ans.pb(i+1);
   }
   if(check(a)){
      cout << ans.size() << "\n";
      for(int i : ans)cout << i << " ";
      return 0;
   }
   // * Check 1
   // * Check 2
   ans = V<int> ();
   a = orig;
   loop(i,0,n-2){
      if(a[i] == a[n-1])continue;
      a[i] = change(a[i]);
      a[i+1] = change(a[i+1]);
      ans.pb(i+1);
   }
   if(check(a)){
      cout << ans.size() << "\n";
      for(int i : ans)cout << i << " ";
      return 0;
   }
   loop(i,1,n-1){
      if(a[i] == a[0])continue;
      a[i] = change(a[i]);
      a[i+1] = change(a[i+1]);
      ans.pb(i+1);
   }
   if(check(a)){
      cout << ans.size() << "\n";
      for(int i : ans)cout << i << " ";
      return 0;
   }
   loop(i,0,n-2){
      if(a[i] == a[n-1])continue;
      a[i] = change(a[i]);
      a[i+1] = change(a[i+1]);
      ans.pb(i+1);
   }
   if(check(a)){
      cout << ans.size() << "\n";
      for(int i : ans)cout << i << " ";
      return 0;
   }
   loop(i,1,n-1){
      if(a[i] == a[0])continue;
      a[i] = change(a[i]);
      a[i+1] = change(a[i+1]);
      ans.pb(i+1);
   }
   if(check(a)){
      cout << ans.size() << "\n";
      for(int i : ans)cout << i << " ";
      return 0;
   }

   // * Check 2
   cout << "-1";
   return 0;
}