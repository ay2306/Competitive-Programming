#include <bits/stdc++.h>
//For ordered_set
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
#define RIT reverse_iterator0
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
const ll N = 1e6+100;
const ll inf = 1e9;
const double pi = acos(-1);
ll fact[N],inv[N];

ll power(ll a, ll n){
   if(n == 0)return 1;
   if(n == 1)return a%MOD;
   ll p = power(a,n/2);
   p*=p;
   if(p >= MOD)p%=MOD;
   if(n&1){
      p*=a;
      if(p >= MOD)p%=MOD;
   }
   return p;
}


void pre(){
   fact[0] = 1;
   fact[1] = 1;
   inv[0] = 1;
   inv[1] = 1;
   loop(i,2,N){
      fact[i]=(fact[i-1]*i);
      inv[i]=(inv[i-1]*power(i,MOD-2));
      if(fact[i] >= MOD)fact[i]%=MOD;
      if(inv[i] >= MOD)inv[i]%=MOD;
   }
}

ll ncr(ll n, ll r){
   // * NCR = (N!)/((N-R)!*R!)
   if(r > n || r < 0)return 0;
   return (((fact[n]*inv[r])%MOD)*inv[n-r])%MOD;
}
ll cal(ll dx, ll dy){
   return ncr(dx+dy,dx);
}
int main(){
   FAST
   pre();
   ll n,m,b;
   cin >> n >> m >> b;
   V<PLL> arr(b);
   V<ll> dp(b+1,0);
   loop(i,0,b)cin >> arr[i].F >> arr[i].S;
   arr.emplace_back(n,m);
   sort(all(arr));
   loop(i,0,b+1){
      dp[i] = cal(arr[i].F-1,arr[i].S-1);
      loop(j,0,i){
         if(arr[j].S > arr[i].S)continue;
         ll now = (cal(arr[i].F-arr[j].F,arr[i].S-arr[j].S)*dp[j])%MOD;
         dp[i]-=now;
         while(dp[i] < 0)dp[i]+=MOD;
         if(dp[i] >= MOD)dp[i]%=MOD;
      }
   }
   cout << dp[b] << "\n";
return 0;
}
