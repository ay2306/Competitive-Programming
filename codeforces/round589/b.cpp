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
int arr[1010][1010];
int rf[1010][1010];
int cf[1010][1010];
ll power(ll n){
   if(n == 0)return 1;
   if(n == 1)return 2;
   ll p = power(n/2);
   p*=p;
   p%=MOD;
   if(n%2 == 1)p*=2;
   p%=MOD;
   return p;
}

int tr[1010],tc[1010];
int main(){
   int n,m;
   cin >> n >> m;
   V<int> r(n);
   V<int> c(m);
   loop(i,0,n)cin >> r[i];
   loop(i,0,m)cin >> c[i];
   loop(i,0,n){
      loop(j,0,r[i])arr[i][j] = 1;
      loop(j,0,min(r[i]+1,m))rf[i][j] = 1;
      loop(j,r[i]+1,m){rf[i][j] = 0;}
   }
   loop(i,0,m){
      loop(j,0,c[i])arr[j][i] = 1;
      loop(j,0,min(c[i]+1,n))cf[j][i] = 1;
      loop(j,c[i]+1,n)cf[j][i] = 0;
   }
   loop(i,0,n){
      loop(j,0,m){
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
   loop(i,0,n){
      loop(j,0,m){
         if(arr[i][j] == 0)break;
         tr[i]++;
      }
      if(r[i] != tr[i]){
         // printf("i = %d, r_i = %d, tr_i = %d\n",i,r[i],tr[i]);
         cout << "0";
         return 0;
      }
   }
   loop(i,0,m){
      loop(j,0,n){
         if(arr[j][i] == 0)break;
         tc[i]++;
      }
      if(c[i] != tc[i]){
         // printf("i = %d, c_i = %d, tc_i = %d\n",i,r[i],tc[i]);
         cout << "0";
         return 0;
      }
   }
   ll cnt = 0;
   loop(i,0,n){
      loop(j,0,m){
         cnt+=(rf[i][j] == 0 && cf[i][j] == 0);
      }
   }
   cout << power(cnt);
   return 0;
}