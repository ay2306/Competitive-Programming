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
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    V<string> a(n);
    loop(i,0,n)cin >> a[i];
    V<int> bc(m+1,0),wc(m+1,0);
    V<V<ll>> dp(m+1,V<ll> (2,inf));
    loop(j,0,m){
        int w = 0;
        loop(i,0,n)w+=(a[i][j]=='#');
        wc[j+1] = n-w;
        bc[j+1] = w;
        // cout << wc[j+1] << " " << bc[j+1] << "\n";
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    loop(i,1,m+1){
        // cout << dp[i][0] << " " << dp[i][1] << endl;
        if(i < x){
            continue;
        }
        ll cost;
        // * If I convert this column black
        cost = bc[i];
        loop(j,1,x){
            cost+=bc[i-j];
        }
        dp[i][0] = min(dp[i][0],cost+dp[i-x][1]);
        loop(j,x,y){
            if(i-j-1 < 0)break;
            cost+=bc[i-j];
            dp[i][0] = min(dp[i][0],cost+dp[i-j-1][1]);
        }
        // * If I convert this column white
        cost = wc[i];
        loop(j,1,x){
            cost+=wc[i-j];
        }
        dp[i][1] = min(dp[i][1],cost+dp[i-x][0]);
        loop(j,x,y){
            if(i-j-1 < 0)break;
            cost+=wc[i-j];
            dp[i][1] = min(dp[i][1],cost + dp[i-j-1][0]);
        }
    }
    cout << min(dp[m][0],dp[m][1]);
   return 0;
}