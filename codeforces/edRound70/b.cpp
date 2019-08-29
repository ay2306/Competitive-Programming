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

int main(){
   FAST
   string a;
   cin >> a;
   V<V<int>> ans(10,V<int>(10,0));
   V<unordered_map<int,int>> modDiffdig(10);
   for(int i = 0; i < 10; ++i){
      for(int j = 1; j <= 20; ++j){
         int val = i*j;
         if(modDiffdig[i].find(val%10) == modDiffdig[i].end()){
            modDiffdig[i][val%10] = j-1;
         }
      }
   }
   V<V<V<int>>> modDiff(10,V<V<int>> (10,V<int>(10,inf)));
   for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; ++j){
         for(int m = 0; m < 10; ++m){
            int a = inf;
            int b = inf;
            if(modDiffdig[i].find(m) != modDiffdig[i].end())a = modDiffdig[i][m];
            if(modDiffdig[j].find(m) != modDiffdig[j].end())b = modDiffdig[j][m];
            modDiff[i][j][m] = min(min(a,b),modDiff[i][j][m]);
         }
      }
   }
   for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; ++j){
         for(int m = 1; m <= (1<<15); ++m){
            int dig = log2(m)+1;
            int bits = __builtin_popcount(m);
            int sum = (i*bits + (dig-bits)*j)%10;
            modDiff[i][j][sum] = min(dig-1,modDiff[i][j][sum]);
         }
      }
   }

   for(int i = 1; i < a.size(); ++i){
      int diff = a[i]-a[i-1];
      if(diff < 0)diff+=10;
      // printf("Transition = %c -> %c , diff = %d\n",a[i-1],a[i],diff);
      for(int k = 0; k < 10; ++k){
         for(int j = k; j < 10; ++j){
            if(ans[k][j] == -1)continue;
            if(modDiff[k][j][diff] == inf){
               ans[k][j] = -1;
               ans[j][k] = -1;
               continue;
            }
            else{
               ans[k][j] += modDiff[k][j][diff];
               if(k != j)ans[j][k] += modDiff[j][k][diff];
            }
         }
      }
   }
   for(int i = 0; i < 10; ++i){
      for(int j = 0; j < 10; ++j){
         cout << ans[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}