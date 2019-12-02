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
#define FILE_READ_OUT freopen("output.txt","w",stdout);(
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
   int n;
   cin >> n;
   string s,t;
   cin >> s >> t;
   string ans = "";
   for(char i = 'a'; i <= 'c' && ans == ""; ++i){

      for(char j = 'a'; j <= 'c' && ans == ""; ++j){
         // if(j == 'b')continue;
         for(char k = 'a'; k <= 'c' && ans == ""; ++k){
            // if(k == 'c')continue;
            unordered_map<char,int> o;
            o[i]++;
            o[j]++;
            o[k]++;
            if(o.size() != 3)continue;
            if(s[0] == i && s[1] == j){
               continue;
            }
            if(s[0] == j && s[1] == k){
               continue;
            }
            if(s[0] == k && s[1] == i){
               continue;
            }
            if(t[0] == i && t[1] == j){
               continue;
            }
            if(t[0] == j && t[1] == k){
               continue;
            }
            if(t[0] == k && t[1] == i){
               continue;
            }
            for(int l = 0; l < 3*n; ++l){
               if(l%3 == 0)ans+=i;
               if(l%3 == 1)ans+=j;
               if(l%3 == 2)ans+=k;
            }
            break;
         }
      }
   }
   if(ans == ""){
      cout << "NO";
   }else{
      cout << "YES\n";
      cout << ans;
   }
   return 0;
}