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
const ll N = 3e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
ll a[N];
ll dp[N][3];
ll n,x;
int main(){;
    cin >> n >> x;
    loop(i,0,n)cin >> a[i];
    dp[0][0] = a[0];
    dp[0][1] = a[0]*x;
    dp[0][2] = -inf;
    ll ans = *max_element(dp[0],dp[0]+3);
    ans = max(ans,0LL);
    loop(i,1,n){
        dp[i][0] = max({0LL,dp[i-1][0]})+a[i];
        dp[i][1] = max({0LL,dp[i-1][0],dp[i-1][1]})+a[i]*x;
        dp[i][2] = max({0LL,dp[i-1][1],dp[i-1][2]})+a[i];
        ans = max({0LL,ans,dp[i][0],dp[i][1],dp[i][2]});
    }
    cout << ans << "\n";
   return 0;
}