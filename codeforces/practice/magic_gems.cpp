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
const int N = 110;
ll m;
ll g[N][N];

void multiply(ll a[N][N], ll b[N][N]){
    ll c[N][N];
    loop(i,0,m){
        loop(j,0,m){
            ll &p = c[i][j];
            p = 0;
            loop(k,0,m){
                p += (a[i][k] * b[k][j])%MOD;
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
    if(n == 1)return;
    power(a,n/2);
    multiply(a,a);
    if(n&1)multiply(a,g);
}
int main(){
    ll n;
    cin >> n >> m;
    ll dp[1010];
    dp[0] = 1;
    dp[1] = 1;
    loop(i,2,1010){
        dp[i]=dp[i-1];
        if(i-m >= 0)dp[i]+=dp[i-m];
        if(dp[i] >= MOD)dp[i]-=MOD;
    }
    if(n <= 500){
        cout << dp[n];
        return 0;
    }
    ll a[N][N];
    loop(i,0,m){
        loop(j,0,m){
            if(i == 0 && (j == 0 || j == m-1))g[i][j] = 1;
            else if(i != 0 && j+1 == i)g[i][j] = 1;
            else g[i][j] = 0;
            a[i][j] = g[i][j];
        }
    }
    power(a,n-m);
    ll ans = 0;
    loop(i,0,m){
        ans += (dp[m-i]*a[0][i])%MOD;
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans;
   return 0;
}