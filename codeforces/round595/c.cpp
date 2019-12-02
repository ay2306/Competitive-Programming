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
const ll N = 1e18;
const ll inf = 1e9;
const double pi = acos(-1);
 
int main(){
   int t;
   cin >> t;
   while(t--){
      ll a,b;
      cin >> a;
      b=a;
      string k = "";
      while(a){
         k+=(a%3 + '0');
         a/=3;
      }
      reverse(all(k));
      bool valid = true;
      loop(i,0,k.size()){
         if(k[i] == '1' || k[i] == '0')continue;
         valid = false;
      }
      if(valid){
         cout << b << "\n";
         continue;
      }
      int n = k.size();
      int ind = n-1;
      int z = -1;
      loopr(i,n-1,0){
         if(k[i] == '1' || k[i] == '0')continue;
         ind = i;
      }
      loopr(i,n-1,0){
         if(k[i] == '0' && i < ind){
            z = i;
            break;
         }
      }
      if(z != -1){
         k[z++] = '1';
         while(z < n)k[z++] = '0';
      }else{
         k = "1" + k;
         for(int i = 1; i < k.size(); ++i){
            k[i] = '0';
         }
      }
      ll ans = 0;
      ll p = 1;
      loopr(i,k.size()-1,0){
         if(k[i] == '1'){
            ans+=(p);
         }
         p*=3;
      }
      cout << ans << "\n";
   }
   return 0;
}