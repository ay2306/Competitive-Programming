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
int value(char a){
   if(a == 'S')return 1;
   if(a == 'E')return 2;
   return 3;
}
void solve(){
   int n,k;
   string m1 = "eSET";
   unordered_map<string,int> m;
   cin >> n >> k;
   V<string> a(n);
   ll ans = 0;
   loop(i,0,n)cin >> a[i],m[a[i]]++;
   loop(i,0,n){
      loop(j,i+1,n){
         if(i == j)continue;
         bool f = true;
         string cur = "";
         loop(p,0,k){
            if(a[i][p] == a[j][p]){
               cur+=a[i][p];
            }
            else{
               cur+=m1[value(a[i][p])^value(a[j][p])];
            }
         }
         ans+=(m[a[i]]*m[a[j]]*m[cur]);
      }
   }
   ans/=3;
   for(auto i: m)ans+=((i.S)*(i.S-1)*(i.S-2))/6;
   cout << ans;
}

int main(){
   FAST
   int t = 1;
//    cin >> t;
   while(t--){
       solve();
   }
   return 0;
}