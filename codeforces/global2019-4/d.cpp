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
const int N = 2005;
void display(V<PII> &ans,V<int> &deg){
   cout << ans.size() << "\n";
   for(auto i: ans){
      cout << i.F << " " << i.S << "\n";
   }
   // cout << "Degrees = ";
   // for(int i = 1; i < deg.size(); ++i)cout << deg[i] << " ";
   // cout << endl;
}
int main(){
   V<int> p(N,0);
   for(int i = 2; i < N; ++i){
      if(p[i] == 0){
         for(int j = 2; i*j < N; ++j)p[i*j]++;
      }
   }
   int n;
   cin >> n;
   V<int> deg(n+1,0);
   V<PII> ans;
   for(int i = 1; i <= n; ++i){
      int a = i;
      int b = i+1;
      if(b > n)b-=n;
      deg[a]++;
      deg[b]++;
      ans.pb(mp(a,b));
   }
   if(p[ans.size()] == 0){
      display(ans,deg);
      return 0;
   }
   int a = 1;
   int b = n-1;
   while(a < b)
   {
      deg[a]++;
      deg[b]++;
      ans.pb(mp(a,b));
      a++;
      b--;
      if(p[ans.size()] == 0){
         display(ans,deg);
         return 0;
      }
      if(a == b || a+1 == b){
         b = n;
         deg[a]++;
         deg[b]++;
         ans.pb(mp(a,b));
         if(p[ans.size()] == 0){
            display(ans,deg);
            return 0;
         }else{
            break;
         }
      }
   }
   cout << "-1";
   return 0;
}