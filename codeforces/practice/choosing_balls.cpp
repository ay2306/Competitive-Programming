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
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    FAST
    int n;
    cin >> n;
    int q;
    cin >> q;
    V<ll> v(n+1);
    loop(i,1,n+1)cin >> v[i];
    V<ll> c(n+1);
    loop(i,1,n+1)cin >> c[i];
    while(q--){
        ll a,b;
        cin >> a >> b;
        int pmax = 0, pmin = 0;
        V<ll> dp(N,LLONG_MIN);
        dp[0] = 0;
        loop(i,1,n+1){
            if(dp[c[i]] != LLONG_MIN){
                dp[c[i]] = max(dp[c[i]],dp[c[i]] + v[i]*a);
            }
            if(pmax != c[i]){
                dp[c[i]] = max(dp[c[i]],dp[pmax] + v[i]*b);
            }
            else{
                dp[c[i]] = max(dp[c[i]],dp[pmin] + v[i]*b);
            }
            if(pmax != c[i]){
                if(dp[c[i]] > dp[pmax]){
                    pmin = pmax;
                    pmax = c[i];
                }else if(dp[c[i]] > dp[pmin]){
                    pmin = c[i];
                }
            }
        }
        cout << dp[pmax] << "\n";
    }
   return 0;
}