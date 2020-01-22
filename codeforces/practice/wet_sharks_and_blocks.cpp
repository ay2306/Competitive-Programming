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
const int N = 200;
int m;
ll g[N][N];
ll f[N];
ll a[N];
void multiply(ll a[N][N], ll b[N][N]){
   ll c[N][N];
   loop(i,0,m){
      loop(j,0,m){
         ll &p = c[i][j];
         p = 0;
         loop(k,0,m){
            p+=((a[i][k]*b[k][j])%MOD);
            if(p >= MOD)p-=MOD;
         }
      }
   }
   loop(i,0,m){
      loop(j,0,m){
         a[i][j] = c[i][j];
      }
   }
}

void power(ll a[N][N], ll n){
   if(n <= 1)return;
   power(a,n/2);
   multiply(a,a);
   if(n&1)multiply(a,g);
}

int main(){
   ll x,y,c,ans,n,b,k;
   cin >> n >> b >> k >> x;
   m = x;
   loop(i,0,n){
      cin >> y;
      a[y]++;
      f[y%x]++;
   }
   if(b == 1){
      cout << f[k] << "\n";
      return 0;
   }
   ll o[N][N];
   loop(i,0,x){
      loop(j,1,10){
         y = (i*10+j)%x;
         g[y][i]+=a[j];
         o[y][i] = g[y][i];
      }
   }
   power(o,b-1);
   ans = 0;
   loop(i,0,x)ans = (ans+(o[k][i]*f[i])%MOD)%MOD;
   cout << ans;
   return 0;
}